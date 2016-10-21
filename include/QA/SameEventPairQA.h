#ifndef SAME_EVENT_PAIR_QA_H
#define SAME_EVENT_PAIR_QA_H

#include "MuonCandidateQA.h"
#include "SameEventPairMaker.h"

class SameEventPairQA : public SameEventPairMaker
{
public:
	virtual const char* classname() const { return "SameEventPairQA"; }
	SameEventPairQA() {}
	~SameEventPairQA() {}

	virtual void initialize(){
		SameEventPairMaker::initialize();


		qaCuts.setDefault( "InvMass", 0, 15 );
		if ( config.exists( nodePath + ".QACuts" ) ){
			qaCuts.init( config, nodePath + ".QACuts" );

			INFO( classname(), "" );
			INFO( classname(), "############### QA Cuts ###################"  );
			qaCuts.report();
			INFO( classname(), "" );
		}

		dimuonBins.load( config, "dimuonBins.invMass" );


		if ( config.getBool( nodePath + ".MakeQA:SingleTrack", true ) ){
			book->cd( "trackQA" );

			trackQA.setHistoBook( book );
			trackQA.setConfig( config );

			trackQA.addCategory( "Like_Sign" );
			trackQA.addCategory( "Unlike_Sign" );
			trackQA.makeDefaultCategory( false );
			MuonCandidateQA::initTrackVariables( trackQA );

			trackQA.makeHistograms( "TrackQABins" );
		}
		
		if ( config.getBool( nodePath + ".MakeQA:Pair", true ) ){
			pairQA.setHistoBook( book );
			pairQA.setConfig( config );
			pairQA.addCategory( "Like_Sign" );
			pairQA.addCategory( "Unlike_Sign" );
			pairQA.makeDefaultCategory( false );
			SameEventPairQA::initPairVariables( pairQA );
			book->cd( "pairQA" );
			pairQA.makeHistograms( "PairQABins" );
		}

		book->cd();
	}


	HistoBins dimuonBins;

	virtual void analyzePair( CandidateTrack * _aTrack, CandidateTrack * _bTrack ){
		

		CandidateTrackMtdPidTraits *aMtdPid = (CandidateTrackMtdPidTraits *)mtdPidTraits->At( _aTrack->mMtdPidTraitsIndex );
		CandidateTrackMtdPidTraits *bMtdPid = (CandidateTrackMtdPidTraits *)mtdPidTraits->At( _bTrack->mMtdPidTraitsIndex );

		TLorentzVector lv1, lv2, lv;
		lv1.SetXYZM( _aTrack->mPMomentum_mX1, _aTrack->mPMomentum_mX2, _aTrack->mPMomentum_mX3, m1 );
		lv2.SetXYZM( _bTrack->mPMomentum_mX1, _bTrack->mPMomentum_mX2, _bTrack->mPMomentum_mX3, m2 );

		lv = lv1 + lv2;

		int iBin = dimuonBins.findBin( lv.M() );
		if ( iBin < 0 ) return;

		double bw = dimuonBins.binWidth( iBin );

		// decide what stuff to keep
		if (  qaCuts["InvMass"]->inInclusiveRange( lv.M() ) ){
			if ( abs(_aTrack->charge() + _bTrack->charge()) > 0 ){
				// INFO( classname(), "Same Sign Pair with M = " << lv.M() );
				if ( config.getBool( nodePath + ".MakeQA:SingleTrack", true ) ){
					book->cd( "trackQA" );
					MuonCandidateQA::fillCandidateTrackQA( trackQA, _aTrack, aMtdPid, "Like_Sign" );
					MuonCandidateQA::fillCandidateTrackQA( trackQA, _bTrack, bMtdPid, "Like_Sign" );
				}
				
				// book->cd();
				// book->fill( "like_sign_selected", lv.M(), 1.0/ bw );
			} else {
				// INFO( classname(), "Opposite Sign Pair with M = " << lv.M() );
				if ( config.getBool( nodePath + ".MakeQA:SingleTrack", true ) ){
					book->cd( "trackQA" );
					MuonCandidateQA::fillCandidateTrackQA( trackQA, _aTrack, aMtdPid, "Unlike_Sign" );
					MuonCandidateQA::fillCandidateTrackQA( trackQA, _bTrack, bMtdPid, "Unlike_Sign" );
				}
				// book->cd();
				// book->fill( "unlike_sign_selected", lv.M(), 1.0/ bw );
			}
		}

		if ( abs(_aTrack->charge() + _bTrack->charge()) > 0 ){
			book->cd();
			book->fill( "like_sign", lv.M(), 1.0/ bw );
		} else {
			book->cd();
			book->fill( "unlike_sign", lv.M(), 1.0/ bw );
		}

		if ( config.getBool( nodePath + ".MakeQA:Pair", true ) ){
			book->cd( "pairQA" );
			// SameEventPairQA::fillPairVariables( pairQA, _aTrack, _bTrack, m1, m2 );
			if ( abs(_aTrack->charge() + _bTrack->charge()) > 0 ){
				SameEventPairQA::fillPairVariables( pairQA, _aTrack, _bTrack, m1, m2, "Like_Sign" );
			} else {
				SameEventPairQA::fillPairVariables( pairQA, _aTrack, _bTrack, m1, m2, "Unlike_Sign");
			}

		}

	}


	static void initPairVariables( TTreeQA &_qaMaker ){
		_qaMaker.i( "deltaPhi" , "dPhi"         , "[rad]" );
		_qaMaker.i( "parentPt" , "Parent p_{T}" , "[GeV/c]"     , "" , "x" );
		_qaMaker.i( "parentM"  , "M"            , "[GeV/c^{2}]" , "" , "x" );
		// _qaMaker.i( "deltaR", "dPhi", "[rad]" );
	}

	static void fillPairVariables( 
			TTreeQA &_qaMaker, 
			CandidateTrack * _aTrack, 
			CandidateTrack * _bTrack, 
			double _m1, double _m2,
			string _cat = "" ){

		TLorentzVector lv1, lv2, lv;
		lv1.SetXYZM( _aTrack->mPMomentum_mX1, _aTrack->mPMomentum_mX2, _aTrack->mPMomentum_mX3, _m1 );
		lv2.SetXYZM( _bTrack->mPMomentum_mX1, _bTrack->mPMomentum_mX2, _bTrack->mPMomentum_mX3, _m2 );
		lv = lv1 + lv2;

		_qaMaker.s( "deltaPhi", lv1.DeltaPhi( lv2 ) );
		_qaMaker.s( "parentPt", lv.Pt() );
		_qaMaker.s( "parentM", lv.M() );

		_qaMaker.fill( _cat );
	}



protected:
	TTreeQA trackQA;
	CutCollection qaCuts;
	TTreeQA pairQA;
	
};


#endif