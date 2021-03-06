#ifndef EVENT_HASHER_H
#define EVENT_HASHER_H

#include "IConfig.h"
#include "IObject.h"
#include "HistoBins.h"
#include "HistoBook.h"

#include <memory>
#include "CandidateEvent.h"

//Root
#include "TStopwatch.h"

class EventHasher : public IConfig, public IObject
{
public:
	virtual const char* classname() const { return "EventHasher"; }
	EventHasher(){

	}
	EventHasher( XmlConfig _config, string _nodePath ) {
		load( _config, _nodePath );
	}
	~EventHasher(){

	}

	void load( XmlConfig _config, string _nodePath ){
		config = _config;
		nodePath = _nodePath;

		vxBins = shared_ptr<HistoBins>( new HistoBins( _config, _nodePath + ".VertexX" )  );
		vyBins = shared_ptr<HistoBins>( new HistoBins( _config, _nodePath + ".VertexY" )  );
		vzBins = shared_ptr<HistoBins>( new HistoBins( _config, _nodePath + ".VertexZ" )  );
		bin16Bins = shared_ptr<HistoBins>( new HistoBins( _config, _nodePath + ".Bin16" )  );
		psiBins = shared_ptr<HistoBins>( new HistoBins( _config, _nodePath + ".Psi2" )  );
		grefmultBins = shared_ptr<HistoBins>( new HistoBins( _config, _nodePath + ".GRefMult" )  );
		runIndexBins = shared_ptr<HistoBins>( new HistoBins( _config, _nodePath + ".RunIndex" )  );

		INFO( classname(), "vxBins : " << vxBins->toString() );
		INFO( classname(), "vyBins : " << vyBins->toString() );
		INFO( classname(), "vzBins : " << vzBins->toString() );
		INFO( classname(), "bin16Bins : " << bin16Bins->toString() );
		INFO( classname(), "Psi2Bins : " << psiBins->toString() );
		INFO( classname(), "grefmultBins : " << grefmultBins->toString() );
		INFO( classname(), "runIndexBins : " << runIndexBins->toString() );

		vxN = vxBins->nBins();
		vyN = vyBins->nBins();
		vzN = vzBins->nBins();
		bin16N = bin16Bins->nBins();
		psiN = psiBins->nBins();
		grefmultN = grefmultBins->nBins();
		runIndexN = runIndexBins->nBins();


		if ( vxN <= 0 ) vxN = 1;
		if ( vyN <= 0 ) vyN = 1;
		if ( vzN <= 0 ) vzN = 1;
		if ( bin16N <= 0 ) bin16N = 1;
		if ( psiN <= 0 ) psiN = 1;
		if ( grefmultN <= 0 ) grefmultN = 1;
		if ( runIndexN <= 0 ) runIndexN = 1;
	}

	long int hash( CandidateEvent * event, shared_ptr<HistoBook> book = nullptr ) {

		// TStopwatch tsw;
		// tsw.Start();
		int vxBin = vxBins->findBin( event->mPrimaryVertex_mX1 );
		int vyBin = vyBins->findBin( event->mPrimaryVertex_mX2 );
		int vzBin = vzBins->findBin( event->mPrimaryVertex_mX3 );
		int bin16Bin = bin16Bins->findBin( event->mBin16 );
		int psiBin = psiBins->findBin( event->psi() );
		int grefmultBin = grefmultBins->findBin( event->mGRefMult );
		int runIndexBin = runIndexBins->findBin( event->mRunIndex );
		

		DEBUG( classname(), "( " << event->mPrimaryVertex_mX1 << ", " << event->mPrimaryVertex_mX2 << ", " << event->mPrimaryVertex_mX3 << ", " << (int)event->mBin16 << ", " << event->psi() << ", " << event->mGRefMult << ", " << event->mRunIndex << " )" );
		DEBUG( classname(), "( " << vxBin << ", " << vyBin << ", " << vzBin << ", " << bin16Bin << ", " << psiBin << ", " << grefmultBin << ", " << runIndexBin << " )" );

		// DEBUG( classname(), "vxBin = "  	<< vxBin );
		// DEBUG( classname(), "vyBin = "  	<< vyBin * vxN );
		// DEBUG( classname(), "vzBin = "  	<< vzBin * (vxN * vyN) << " bc " << vxN << ", " << vyN );
		// DEBUG( classname(), "bin16Bin = "  	<< bin16Bin * (vxN * vyN * vzN) );
		// DEBUG( classname(), "psiBin = "  	<< psiBin * (vxN * vyN * vzN * bin16N) );
		// DEBUG( classname(), "grefmultBin = "<< grefmultBin * (vxN * vyN * vzN * bin16N * psiN ) );
		// DEBUG( classname(), "grefmultBin = "<< grefmultBin * (vxN * vyN * vzN * bin16N * psiN ) );

		// long int i = vxBin + ( vyBin * vxN ) + ( vzBin * vxN * vyN ) + ( bin16Bin * vxN * vyN * vzN ) + ( psiBin * vxN * vyN * vzN * bin16N );
		long int i = hash_vx( vxBin ) + hash_vy( vyBin ) + hash_vz( vzBin ) + hash_bin16( bin16Bin ) + hash_psi( psiBin ) + hash_grefmult( grefmultBin ) + hash_runIndex( runIndexBin );

		if ( (vxBin < 0 && vxN > 1) || (vyBin < 0 && vyN > 1) || (vzBin < 0 && vzN > 1) || (bin16Bin < 0 && bin16N > 1) || (psiBin < 0 && psiN > 1) ) {
			WARN( classname(), "EventHash Out of Bounds: " );
			WARN( classname(), "( " << event->mPrimaryVertex_mX1 << ", " << event->mPrimaryVertex_mX2 << ", " << event->mPrimaryVertex_mX3 << ", " << (int)event->mBin16 << ", " << event->psi() << ", " << event->mGRefMult << " )" );
			WARN( classname(), "( " << vxBin                     << ", " << vyBin                     << ", " << vzBin                     << ", " << bin16Bin           << ", " << psiBin       << ", " << grefmultBin      << " )" );
			return -1;
		}
		// tsw.Stop();
		// INFO( classname(), "Finding bins : " << tsw.RealTime() << ", " << tsw.CpuTime() );

		return i;
	}


	void unhash( long int hash ){
		int vx = hash % vxN;
		int vy = (hash / vxN) % vyN;
		int vz = (hash / ( vxN * vyN )) % vzN;
		int bin16 = ( hash / ( vxN * vyN * vzN ) ) % bin16N;
		int psi = ( hash / ( vxN * vyN * vzN * bin16N ) ) % psiN;
		int grefmult = ( hash / ( vxN * vyN * vzN * bin16N * psiN ) ) % grefmultN;
		int runIndex = ( hash / ( vxN * vyN * vzN * bin16N * psiN * grefmultN) ) % runIndexN;
		INFO( classname(), "vx=" << vx << ", vy=" << vy << ", vz=" << vz << ", bin16=" << bin16 << ", psi=" << psi << ", grefmult=" << grefmult << ", runIndex=" << runIndex );
		INFO( classname(), "R(vx)=" << vxBins->toString( vx ) );
		INFO( classname(), "R(vy)=" << vyBins->toString( vy ) );
		INFO( classname(), "R(vz)=" << vzBins->toString( vz ) );
		INFO( classname(), "R(bin16)=" << bin16Bins->toString( bin16 ) );
		INFO( classname(), "R(psi)=" << psiBins->toString( psi ) );
		INFO( classname(), "R(grefmult)=" << grefmultBins->toString( grefmult ) );
		INFO( classname(), "R(runIndex)=" << runIndexBins->toString( runIndex ) );
	}

	long int hash_vx( int vxBin ){
		if ( vxBin < 0 )
			vxBin = 0;
		return vxBin;
	}

	long int hash_vy( int vyBin ){
		int b = vyBin * vxN;
		if (b < 0 ) b = 0;
		DEBUG( classname(), "b = " << b );
		return b;
	}
	long int hash_vz( int vzBin ){
		int b = vzBin * vxN * vyN;
		if (b < 0 ) b = 0;
		DEBUG( classname(), "b = " << b );
		return b;
	}
	long int hash_bin16( int bin16Bin ){
		int b = bin16Bin * vxN * vyN * vzN;
		if (b < 0 ) b = 0;
		DEBUG( classname(), "b = " << b );
		return b;
	}
	long int hash_psi( int psiBin ){
		int b = psiBin * vxN * vyN * vzN * bin16N;
		if (b < 0 ) b = 0;
		DEBUG( classname(), "b = " << b );
		return b;
	}
	long int hash_grefmult( int grefmultBin ){
		int b = grefmultBin * vxN * vyN * vzN * bin16N * psiN;
		if (b < 0 ) b = 0;
		DEBUG( classname(), "b = " << b );
		return b;
	}
	long int hash_runIndex( int runIndexBin ){
		int b = runIndexBin * vxN * vyN * vzN * bin16N * psiN * grefmultN;
		if (b < 0 ) b = 0;
		DEBUG( classname(), "b = " << b );
		return b;
	}

	long int maxPossibleHash(){
		int vxBin    = vxN - 1;
		int vyBin    = vyN - 1;
		int vzBin    = vzN - 1;
		int bin16Bin = bin16N - 1;
		int psiBin   = psiN - 1;
		int grefmultBin   = grefmultN - 1;
		int runIndexBin   = runIndexN - 1;

		// long int i = vxBin + ( vyBin * vxN ) + ( vzBin * vxN * vyN ) + ( bin16Bin * vxN * vyN * vzN ) + ( psiBin * vxN * vyN * vzN * bin16N );
		long int i = hash_vx( vxBin ) + hash_vy( vyBin ) + hash_vz( vzBin ) + hash_bin16( bin16Bin ) + hash_psi( psiBin ) + hash_grefmult( grefmultBin ) + hash_runIndex( runIndexBin );
		return i;
	}

protected:

	shared_ptr<HistoBins> 	vzBins, 
							vxBins, 
							vyBins,
							bin16Bins,
							grefmultBins,
							psiBins,
							runIndexBins;
	int vxN, vyN, vzN, bin16N, psiN, grefmultN, runIndexN;


	
};


#endif