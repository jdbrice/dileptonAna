#ifndef MIXED_EVENT_CANDIDATE_SKIMMER_H
#define MIXED_EVENT_CANDIDATE_SKIMMER_H

#include "IObject.h"
using namespace jdb;

#include <unordered_map>
#include <vector>

#include "Candidate.h"
#include "EventHasher.h"
#include "IMixedEventPairTreeMaker.h"
#include "CandidateFilter.h"
#include "PairFilter.h"
#include "CutCollectionTreeMaker.h"

#include "TRandom3.h"

class MixedEventCandidateSkimmer : public CandidateSkimmer
{
public:
	virtual const char * classname() const { return "MixedEventCandidateSkimmer"; }
	MixedEventCandidateSkimmer() {}
	~MixedEventCandidateSkimmer() {}

	virtual void overrideConfig(){
		// set the number of Event Loops to 2!
		config.set( nodePath + ":nEventLoops", "2" );
	}

	virtual void initialize(){
		CandidateSkimmer::initialize();

		nPerEventHash = config.getInt( nodePath + ".Mixing:nPerEventHash", 10 );
		minEventHash = config.getInt( nodePath + ".Mixing:min", 0 );
		maxEventHash = config.getInt( nodePath + ".Mixing:max", 100 );

		hasher.load( config, nodePath + ".MixedEventBins" );

		if ( minEventHash < 0 ){
			minEventHash = 0;
			WARN( classname(), "MinEventHash was outside limits, set to 0" );
		}
		if ( maxEventHash > hasher.maxPossibleHash() || maxEventHash < minEventHash ){
			maxEventHash = hasher.maxPossibleHash();
			WARN( classname(), "maxEventHash was out of limits, set to " << maxEventHash );
		}
		INFO( classname(), "Making Buffers for EventHash from " << minEventHash << " to " << maxEventHash );

		m1 = config.getDouble( nodePath + ".Particles:mass1", 0.0511 );
		m2 = config.getDouble( nodePath + ".Particles:mass2", 0.0511 );

		CandidateFilter::setDefaultMuonCuts( trackCuts );
		if ( config.exists( nodePath + ".MuonCandidateCuts" ) ){
			trackCuts.init( config, nodePath + ".MuonCandidateCuts" );

			INFO( classname(), "" );
			INFO( classname(), "############### Muon Cuts ###################"  );
			trackCuts.report();
			INFO( classname(), "" );
		}

		PairFilter::setDefaultPairCuts( pairCuts );
		if ( config.exists( nodePath + ".SameEventPairCuts" ) ){
			pairCuts.init( config, nodePath + ".SameEventPairCuts" );	// TODO: either make a diff config or change name to show that it is used for both

			INFO( classname(), "" );
			INFO( classname(), "############### Pair Cuts ###################"  );
			pairCuts.report();
			INFO( classname(), "" );
		}

		tofPid = config.getBool( nodePath + ".MuonCandidateCuts:tofPid", false );
		string pfSigmaDeltaZ = config.q( nodePath + ".MtdParams.XmlFunction{name==SigmaMtdDeltaZ}" );
		string pfSigmaDeltaY = config.q( nodePath + ".MtdParams.XmlFunction{name==SigmaMtdDeltaY}" );
		string pfSigmaDeltaTOF = config.q( nodePath + ".MtdParams.XmlFunction{name==SigmaMtdDeltaTOF}" );
		if ( config.exists( pfSigmaDeltaZ ) ){
			INFOC( "=================== SIGMA DELTA Z ENABLED ========================" );
			fSigmaDeltaZ.set( config, pfSigmaDeltaZ );
		}
		if ( config.exists( pfSigmaDeltaY ) ){
			INFOC( "=================== SIGMA DELTA Y ENABLED ========================" );
			fSigmaDeltaY.set( config, pfSigmaDeltaY );
		}
		if ( config.exists( pfSigmaDeltaTOF ) ){
			INFOC( "=================== SIGMA DELTA TOF ENABLED ========================" );
			fSigmaDeltaTOF.set( config, pfSigmaDeltaTOF );
		}

		
		// rand used for choosing which buffered track to overwrite when the buffer is full
		rander.SetSeed( 0 ); // this is unique for every run
	}
protected:

	CutCollection trackCuts;
	CutCollection pairCuts;
	TRandom3 rander;

	double m1, m2;

	EventHasher hasher;
	int nPerEventHash;
	int minEventHash;
	int maxEventHash;
	int cEventHash = -1;

	bool tofPid = false;
	XmlFunction fSigmaDeltaZ, fSigmaDeltaY, fSigmaDeltaTOF;

	/* Buffer of mixed event candidates
	 * key 		: EventHash
	 * value 	: vector of Candidate objects where the length is determined at runtime by the requested number to mix
	 */
	unordered_map< int, vector< shared_ptr<Candidate> > > buffer;

	/* KeepTrack or not
	 * 
	 * Decides whether or not to keep a track based on the provided Track cuts
	 * @aTrack 	CandidateTrack to test
	 * @return bool
	 */
	bool keepTrack( CandidateTrack *aTrack ){
		// CandidateTrackMtdPidTraits *mtdPid = (CandidateTrackMtdPidTraits *)mtdPidTraits->At( aTrack->mMtdPidTraitsIndex );
		// return CandidateFilter::isMuon( aTrack, mtdPid, trackCuts,  makeTrackCutQA ? book : nullptr );
		DEBUG( classname(), "("<< aTrack << ")" );
		
		if ( aTrack->mMtdPidTraitsIndex < 0) return false;


		bool goodTrack = CandidateFilter::isGoodTrack( aTrack, trackCuts, makeTrackCutQA ? book : nullptr, "MtdMuon" );

		if (false == goodTrack) return false;

		TF1 * f1SigmaDeltaZ   = fSigmaDeltaZ.getTF1().get();
		TF1 * f1SigmaDeltaY   = fSigmaDeltaY.getTF1().get();
		TF1 * f1SigmaDeltaTOF = fSigmaDeltaTOF.getTF1().get();
		CandidateTrackMtdPidTraits *mtdPid = (CandidateTrackMtdPidTraits *)mtdPidTraits->At( aTrack->mMtdPidTraitsIndex );
		bool mtdMuon = CandidateFilter::isMtdMuon(  aTrack, 
													mtdPid, 
													trackCuts, 
													makeTrackCutQA ? book : nullptr,
													"",
													f1SigmaDeltaZ,
													f1SigmaDeltaY,
													f1SigmaDeltaTOF );

		if ( false == mtdMuon ) return false;


		if ( tofPid && aTrack->mBTofPidTraitsIndex >= 0 ){
			CandidateTrackBTofPidTraits *btofPid = (CandidateTrackBTofPidTraits *)btofPidTraits->At( aTrack->mBTofPidTraitsIndex );
			bool tofMuon = CandidateFilter::isTofMuon(  aTrack,
														btofPid,
														trackCuts,
														makeTrackCutQA ? book : nullptr );

			if ( false == tofMuon ) return false;
		}	// TOF PID

		return true;
	}

	/* Analyze Event
	 * if iEventLoop == 0 then it fills all buffers 
	 * if iEventLoop == 1 then it does the event mixing
	 */
	virtual void analyzeEvent() {

		if ( event->mBin16 < 0 || event->mBin16 > 50 )
			return;

		if ( event->mBin16 > 4) return;

		cEventHash = hasher.hash( event );

		if ( iEventLoop == 0 ){
			book->cd();
			book->fill( "EventHash", cEventHash );	
		}
		
		if ( cEventHash >= minEventHash && cEventHash <= maxEventHash  ){

			if ( iEventLoop == 0 && isBufferFull( cEventHash ) ){
				if ( allBuffersFull() ){
					cout << "\n\n" << endl;
					INFO( classname(), "Skipping to next Event Loop since buffers are full" );
					finishCurrentEventLoopEarly = true;
				}
				return;
			}

			analyzeTrack();

		}
	}

	bool bufferContains( vector<shared_ptr<Candidate> > &buffer, shared_ptr<Candidate> _cand ){
		for ( shared_ptr<Candidate> c : buffer  ){
			if ( *c == *_cand ){
				return true;
			}
		}
		return false;
	}

	void addToBuffer( shared_ptr<Candidate>  _cand ){
		
		// need a bit more logic here
		// no need to check for existance first because if it doesnt exist then it must be empty
		// times two because we may have some same-event tracks, we want to make sure we have at least nPerEventHash available
		int mod = 3;
		if ( buffer[ cEventHash ].size() < nPerEventHash * mod )
			buffer[ cEventHash ].push_back( _cand );
		else {
			// it is full so we need to replace one
			int rIndex = rander.Integer( buffer[ cEventHash ].size() );
			buffer[ cEventHash ][ rIndex ] = _cand;
		}
	}

	bool isBufferFull( int eventHash ){
		int mod = 3;
		if ( buffer.count( eventHash ) > 0 && buffer[ eventHash ].size() >= nPerEventHash * mod )
			return true;
		return false;
	}

	bool allBuffersFull(  ){
		for ( int i = minEventHash; i <= maxEventHash; i++ ){
			if ( false == isBufferFull( i ) ){
				return false;
			}
		}
		return true;
	}

	virtual void preMake(){

		book->cd();
		CutCollectionTreeMaker::makeCutTree( trackCuts, "trackCuts" );
		CutCollectionTreeMaker::makeCutTree( pairCuts, "pairCuts" );

	}


	virtual void analyzeTrack(  ){
		
		CandidateTrack* aTrack = nullptr;
		CandidateTrackMtdPidTraits *aMtdPid = nullptr;
		CandidateTrackBTofPidTraits *aBTofPid = nullptr;

		int nTracks = tracks->GetEntries();
		for ( int iTrack = 0; iTrack < nTracks; iTrack++ ){
			aTrack = (CandidateTrack*)tracks->At( iTrack );
			if ( !keepTrack ( aTrack )) continue;
			
			if ( aTrack->mMtdPidTraitsIndex >= 0 )
				aMtdPid = (CandidateTrackMtdPidTraits *)mtdPidTraits->At( aTrack->mMtdPidTraitsIndex );
			else 
				mtdPidTraits = nullptr;

			shared_ptr<Candidate> cand = shared_ptr<Candidate>( new Candidate() );
			cand->set( event, aTrack, aMtdPid );



			if ( iEventLoop == 0 ){
				addToBuffer( cand );
			} else {
				mixTrack( cand );
			}
		} // end track loop

	}

	virtual void postMake(){
		book->cd();
		int tFull = 0;
		for ( auto kv : buffer ){
			INFO( classname(), kv.first << " has " << kv.second.size() );
			book->fill( "EventHashN", kv.first, kv.second.size() );

			if ( kv.second.size() >= nPerEventHash )
				tFull++;
		}

		INFO( classname(), "There are " << ts( tFull ) << " / " << (hasher.maxPossibleHash()+1) << " full buffers" );
	}


	virtual bool keepMixedTracks( shared_ptr<Candidate> _cand1, shared_ptr<Candidate> _cand2 ){
		return true;
		// subclass should override
	}

	virtual void mixTrack( shared_ptr<Candidate> _cand ){
		// NoOP
		// subclass should override 
	}


};

#endif