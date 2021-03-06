

// RooBarb
#include "XmlConfig.h"
#include "TaskEngine.h"
#include "SharedTreeAnalyzer.h"
using namespace jdb;

// STL
#include <iostream>
#include <exception>


#include "EventXMLExporter.h"
#include "SignalCocktailPlotter.h"
#include "PidEfficiencyMaker.h"
#include "MtdSigmaMaker.h"

// Efficiency
#include "EfficiencyMaker.h"

// Project
#include "RunByRunQAMaker.h"
#include "RunByRunReportMaker.h"
#include "RunByRunCandidateQAMaker.h"
#include "MuonCandidateQA.h"
#include "TriggerPatchQA.h"
#include "SameEventPairQA.h"
#include "MixedEventPairQAMaker.h"
#include "PidPlotMaker.h"
#include "PidPdfMaker.h"

// Exporters
#include "CandidateCSVExporter.h"
#include "CandidatePairCSVExporter.h"

#include "PicoDstSkimmer.h"
#include "PicoDst16aSkimmer.h"

// Candidate Makers
#include "CandidateMaker.h"
#include "EventPlaneCandidateMaker.h"
#include "MuonCandidateMaker.h"
#include "ElectronMuonCandidateMaker.h"
#include "ElectronCandidateMaker.h"

// Mixing Event
// #include "MixedEventMassPlotter.h"
#include "MixedEventCandidateSkimmer.h"
#include "MixedEventPairMaker.h"

#include "EventPlaneHistoMaker.h"
#include "EventPlaneOffsetFitter.h"

// Skimmers
#include "SharedPicoDstSkimmer.h"
#include "CandidateSkimmer.h"

#include "SameEventPairMaker.h"
#include "SameEventPairTreeMaker.h"
#include "InvariantMassPlotMaker.h"
#include "BackgroundMaker.h"
#include "FitnessMaker.h"

#include "InvMassHistoMaker.h"


#include "CommandRunner.h"
#include "CandidateMakerProxy.h"

#include "UnitTestProductionUtils.h"
#include "UnitTestEventHasher.h"

#include "VegaXmlPlotter.h"

#include "PythiaSkimmer.h"

#include "MtdGeometryWeightMapMaker.h"
#include "MtdTreeMaker.h"

#include "AcceptanceFixer.h"
#include "EmbeddingMaker.h"

TRandom3 SameEventPairQA::rnd;

int main( int argc, char* argv[] ) {


	TaskFactory::registerTaskRunner<SharedPicoDstSkimmer>( "SharedPicoDstSkimmer" );
	// RunByRun QA
	TaskFactory::registerTaskRunner<RunByRunQAMaker>( "RunByRunQAMaker" );
	TaskFactory::registerTaskRunner<RunByRunReportMaker>( "RunByRunReportMaker" );
	TaskFactory::registerTaskRunner<RunByRunCandidateQAMaker>( "RunByRunCandidateQAMaker" );
	TaskFactory::registerTaskRunner<TriggerPatchQA>( "TriggerPatchQA" );
	TaskFactory::registerTaskRunner<MuonCandidateQA>( "MuonCandidateQA" );
	TaskFactory::registerTaskRunner<SameEventPairQA>( "SameEventPairQA" );
	TaskFactory::registerTaskRunner<MixedEventPairQAMaker>( "MixedEventPairQAMaker" );
	TaskFactory::registerTaskRunner<PidPlotMaker>( "PidPlotMaker" );
	TaskFactory::registerTaskRunner<PidPdfMaker>( "PidPdfMaker" );

	TaskFactory::registerTaskRunner<CandidateCSVExporter>( "CandidateCSVExporter" );
	TaskFactory::registerTaskRunner<CandidatePairCSVExporter>( "CandidatePairCSVExporter" );

	TaskFactory::registerTaskRunner<PicoDst16aSkimmer>( "PicoDst16aSkimmer" );
	TaskFactory::registerTaskRunner<PicoDstSkimmer>( "PicoDstSkimmer" );
	TaskFactory::registerTaskRunner<CandidateMaker>( "CandidateMaker" );
	TaskFactory::registerTaskRunner<MuonCandidateMaker>( "MuonCandidateMaker" );
	TaskFactory::registerTaskRunner<ElectronMuonCandidateMaker>( "ElectronMuonCandidateMaker" );
	TaskFactory::registerTaskRunner<ElectronCandidateMaker>( "ElectronCandidateMaker" );
	
	TaskFactory::registerTaskRunner<EventPlaneCandidateMaker>( "EventPlaneCandidateMaker" );
	TaskFactory::registerTaskRunner<EventPlaneHistoMaker>( "EventPlaneHistoMaker" );
	TaskFactory::registerTaskRunner<EventPlaneOffsetFitter>( "EventPlaneOffsetFitter" );
	TaskFactory::registerTaskRunner<CandidateSkimmer>( "CandidateSkimmer" );

	TaskFactory::registerTaskRunner<SameEventPairMaker>( "SameEventPairMaker" );
	TaskFactory::registerTaskRunner<SameEventPairTreeMaker>( "SameEventPairTreeMaker" );
	// TaskFactory::registerTaskRunner<MixedEventMassPlotter>( "MixedEventMassPlotter" );
	TaskFactory::registerTaskRunner<BackgroundMaker>( "BackgroundMaker" );
	TaskFactory::registerTaskRunner<FitnessMaker>( "FitnessMaker" );

	// Plot Makers
	TaskFactory::registerTaskRunner<InvariantMassPlotMaker>( "InvariantMassPlotMaker" );
	TaskFactory::registerTaskRunner<InvMassHistoMaker>( "InvMassHistoMaker" );
	TaskFactory::registerTaskRunner<VegaXmlPlotter>( "VegaXmlPlotter" );

	TaskFactory::registerTaskRunner<MixedEventCandidateSkimmer>( "MixedEventCandidateSkimmer" );
	TaskFactory::registerTaskRunner<MixedEventPairMaker>( "MixedEventPairMaker" );

	//TaskUtils
	TaskFactory::registerTaskRunner<CommandRunner>( "CommandRunner" );
	TaskFactory::registerTaskRunner<CandidateMakerProxy>( "CandidateMakerProxy" );


	// UnitTests
	TaskFactory::registerTaskRunner<UnitTestProductionUtils>( "UnitTestProductionUtils" );
	TaskFactory::registerTaskRunner<UnitTestEventHasher>( "UnitTestEventHasher" );

	TaskFactory::registerTaskRunner<PythiaSkimmer>( "PythiaSkimmer" );

	TaskFactory::registerTaskRunner<MtdGeometryWeightMapMaker>( "MtdGeometryWeightMapMaker" );
	TaskFactory::registerTaskRunner<MtdTreeMaker>( "MtdTreeMaker" );

	TaskFactory::registerTaskRunner<AcceptanceFixer>( "AcceptanceFixer" );

	TaskFactory::registerTaskRunner<EmbeddingMaker>( "EmbeddingMaker" );
	TaskFactory::registerTaskRunner<EfficiencyMaker>( "EfficiencyMaker" );

	TaskFactory::registerTaskRunner<MtdSigmaMaker>( "MtdSigmaMaker" );
	TaskFactory::registerTaskRunner<PidEfficiencyMaker>( "PidEfficiencyMaker" );

	TaskFactory::registerTaskRunner<SignalCocktailPlotter>( "SignalCocktailPlotter" );
	TaskFactory::registerTaskRunner<EventXMLExporter>( "EventXMLExporter" );

	TaskEngine engine( argc, argv );

	return 0;
}
