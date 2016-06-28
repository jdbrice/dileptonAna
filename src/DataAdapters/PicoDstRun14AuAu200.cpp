#include "PicoDstRun14AuAu200.h"


PicoDstRun14AuAu200::PicoDstRun14AuAu200(TTree *tree) : fChain(0) 
{
   Init(tree);
}

PicoDstRun14AuAu200::~PicoDstRun14AuAu200()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t PicoDstRun14AuAu200::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t PicoDstRun14AuAu200::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}


// {
//   // st_mtd stream
//   450601, // dimuon
//   450611, // dimuon
//   450621, // dimuon
//   450631, // dimuon
//   450641, // dimuon
//   450604,    // dimuon-30-hft (production_2014)
//   450605,    // dimuon-5-hft (production_mid_2014, production_low_2014)
//   450606,    // dimuon-5-hft (production_mid_2014)
//   450602,    // e-mu (production_2014)
//   450612,    // e-mu (production_2014, production_low_2014)
//   450622,    // e-mu (production_2014, production_low_2014)
//   450632,    // e-mu (production_mid_2014)
//   450642,    // e-mu (production_2014, production_low_2014)
//   450600,    // single-muon (production_2014)
//   450610,    // single-muon (production_2014, production_low_2014)
//   450620,    // single-muon (production_2014, production_low_2014)
//   450630,    // single-muon (production_mid_2014)
//   450640     // single-muon (production_2014, production_low_2014)
// }; // Run14 AuAu200 GeV StMtd Stream




void PicoDstRun14AuAu200::Init(TTree *tree)
{
   IPicoDst::Init( tree );
   // if (!tree) return;
   // fChain = tree;
   // fCurrent = -1;
   // fChain->SetMakeClass(1);

   // fChain->SetBranchAddress("Event", &Event_, &b_Event_);
   // fChain->SetBranchAddress("Event.mRunId", Event_mRunId, &b_Event_mRunId);
   // fChain->SetBranchAddress("Event.mEventId", Event_mEventId, &b_Event_mEventId);
   // fChain->SetBranchAddress("Event.mFillId", Event_mFillId, &b_Event_mFillId);
   // fChain->SetBranchAddress("Event.mBField", Event_mBField, &b_Event_mBField);
   // fChain->SetBranchAddress("Event.mPrimaryVertex.mX1", Event_mPrimaryVertex_mX1, &b_Event_mPrimaryVertex_mX1);
   // fChain->SetBranchAddress("Event.mPrimaryVertex.mX2", Event_mPrimaryVertex_mX2, &b_Event_mPrimaryVertex_mX2);
   // fChain->SetBranchAddress("Event.mPrimaryVertex.mX3", Event_mPrimaryVertex_mX3, &b_Event_mPrimaryVertex_mX3);
   // fChain->SetBranchAddress("Event.mSecondVertex.mX1", Event_mSecondVertex_mX1, &b_Event_mSecondVertex_mX1);
   // fChain->SetBranchAddress("Event.mSecondVertex.mX2", Event_mSecondVertex_mX2, &b_Event_mSecondVertex_mX2);
   // fChain->SetBranchAddress("Event.mSecondVertex.mX3", Event_mSecondVertex_mX3, &b_Event_mSecondVertex_mX3);
   // fChain->SetBranchAddress("Event.mPrimaryVertexError.mX1", Event_mPrimaryVertexError_mX1, &b_Event_mPrimaryVertexError_mX1);
   // fChain->SetBranchAddress("Event.mPrimaryVertexError.mX2", Event_mPrimaryVertexError_mX2, &b_Event_mPrimaryVertexError_mX2);
   // fChain->SetBranchAddress("Event.mPrimaryVertexError.mX3", Event_mPrimaryVertexError_mX3, &b_Event_mPrimaryVertexError_mX3);
   // fChain->SetBranchAddress("Event.mTriggerWord", Event_mTriggerWord, &b_Event_mTriggerWord);
   // fChain->SetBranchAddress("Event.mTriggerWordMtd", Event_mTriggerWordMtd, &b_Event_mTriggerWordMtd);
   // fChain->SetBranchAddress("Event.mRefMultFtpcEast", Event_mRefMultFtpcEast, &b_Event_mRefMultFtpcEast);
   // fChain->SetBranchAddress("Event.mRefMultFtpcWest", Event_mRefMultFtpcWest, &b_Event_mRefMultFtpcWest);
   // fChain->SetBranchAddress("Event.mRefMultNeg", Event_mRefMultNeg, &b_Event_mRefMultNeg);
   // fChain->SetBranchAddress("Event.mRefMultPos", Event_mRefMultPos, &b_Event_mRefMultPos);
   // fChain->SetBranchAddress("Event.mRefMult2NegEast", Event_mRefMult2NegEast, &b_Event_mRefMult2NegEast);
   // fChain->SetBranchAddress("Event.mRefMult2PosEast", Event_mRefMult2PosEast, &b_Event_mRefMult2PosEast);
   // fChain->SetBranchAddress("Event.mRefMult2NegWest", Event_mRefMult2NegWest, &b_Event_mRefMult2NegWest);
   // fChain->SetBranchAddress("Event.mRefMult2PosWest", Event_mRefMult2PosWest, &b_Event_mRefMult2PosWest);
   // fChain->SetBranchAddress("Event.mRefMultHalfNegEast", Event_mRefMultHalfNegEast, &b_Event_mRefMultHalfNegEast);
   // fChain->SetBranchAddress("Event.mRefMultHalfPosEast", Event_mRefMultHalfPosEast, &b_Event_mRefMultHalfPosEast);
   // fChain->SetBranchAddress("Event.mRefMultHalfNegWest", Event_mRefMultHalfNegWest, &b_Event_mRefMultHalfNegWest);
   // fChain->SetBranchAddress("Event.mRefMultHalfPosWest", Event_mRefMultHalfPosWest, &b_Event_mRefMultHalfPosWest);
   // fChain->SetBranchAddress("Event.mGRefMult", Event_mGRefMult, &b_Event_mGRefMult);
   // fChain->SetBranchAddress("Event.mNHitsHFT[4]", Event_mNHitsHFT, &b_Event_mNHitsHFT);
   // fChain->SetBranchAddress("Event.mNVpdHitsEast", Event_mNVpdHitsEast, &b_Event_mNVpdHitsEast);
   // fChain->SetBranchAddress("Event.mNVpdHitsWest", Event_mNVpdHitsWest, &b_Event_mNVpdHitsWest);
   // fChain->SetBranchAddress("Event.mNT0", Event_mNT0, &b_Event_mNT0);
   // fChain->SetBranchAddress("Event.mVzVpd", Event_mVzVpd, &b_Event_mVzVpd);
   // fChain->SetBranchAddress("Event.mZDCx", Event_mZDCx, &b_Event_mZDCx);
   // fChain->SetBranchAddress("Event.mBBCx", Event_mBBCx, &b_Event_mBBCx);
   // fChain->SetBranchAddress("Event.mBackgroundRate", Event_mBackgroundRate, &b_Event_mBackgroundRate);
   // fChain->SetBranchAddress("Event.mBbcBlueBackgroundRate", Event_mBbcBlueBackgroundRate, &b_Event_mBbcBlueBackgroundRate);
   // fChain->SetBranchAddress("Event.mBbcYellowBackgroundRate", Event_mBbcYellowBackgroundRate, &b_Event_mBbcYellowBackgroundRate);
   // fChain->SetBranchAddress("Event.mBbcEastRate", Event_mBbcEastRate, &b_Event_mBbcEastRate);
   // fChain->SetBranchAddress("Event.mBbcWestRate", Event_mBbcWestRate, &b_Event_mBbcWestRate);
   // fChain->SetBranchAddress("Event.mZdcEastRate", Event_mZdcEastRate, &b_Event_mZdcEastRate);
   // fChain->SetBranchAddress("Event.mZdcWestRate", Event_mZdcWestRate, &b_Event_mZdcWestRate);
   // fChain->SetBranchAddress("Event.mVpd[64]", Event_mVpd, &b_Event_mVpd);
   // fChain->SetBranchAddress("Event.mZdcSumAdcEast", Event_mZdcSumAdcEast, &b_Event_mZdcSumAdcEast);
   // fChain->SetBranchAddress("Event.mZdcSumAdcWest", Event_mZdcSumAdcWest, &b_Event_mZdcSumAdcWest);
   // fChain->SetBranchAddress("Event.mZdcSmdEastHorizontal[8]", Event_mZdcSmdEastHorizontal, &b_Event_mZdcSmdEastHorizontal);
   // fChain->SetBranchAddress("Event.mZdcSmdEastVertical[8]", Event_mZdcSmdEastVertical, &b_Event_mZdcSmdEastVertical);
   // fChain->SetBranchAddress("Event.mZdcSmdWestHorizontal[8]", Event_mZdcSmdWestHorizontal, &b_Event_mZdcSmdWestHorizontal);
   // fChain->SetBranchAddress("Event.mZdcSmdWestVertical[8]", Event_mZdcSmdWestVertical, &b_Event_mZdcSmdWestVertical);
   // fChain->SetBranchAddress("Event.mSpaceCharge", Event_mSpaceCharge, &b_Event_mSpaceCharge);
   // fChain->SetBranchAddress("Event.mbTofTrayMultiplicity", Event_mbTofTrayMultiplicity, &b_Event_mbTofTrayMultiplicity);
   // fChain->SetBranchAddress("Event.mNumberOfGlobalTracks", Event_mNumberOfGlobalTracks, &b_Event_mNumberOfGlobalTracks);
   // fChain->SetBranchAddress("Event.mRanking", Event_mRanking, &b_Event_mRanking);
   // fChain->SetBranchAddress("Event.mNBEMCMatch", Event_mNBEMCMatch, &b_Event_mNBEMCMatch);
   // fChain->SetBranchAddress("Event.mNBTOFMatch", Event_mNBTOFMatch, &b_Event_mNBTOFMatch);
   // fChain->SetBranchAddress("Event.mBbcAdcEast[24]", Event_mBbcAdcEast, &b_Event_mBbcAdcEast);
   // fChain->SetBranchAddress("Event.mBbcAdcWest[24]", Event_mBbcAdcWest, &b_Event_mBbcAdcWest);
   // fChain->SetBranchAddress("Event.mHT_Th[4]", Event_mHT_Th, &b_Event_mHT_Th);
   // fChain->SetBranchAddress("Event.mJP_Th[4]", Event_mJP_Th, &b_Event_mJP_Th);
   // /***********************************************************************************************/
   // // EventPlane
   // fChain->SetBranchAddress("EventPlane", &EventPlane_, &b_EventPlane_);
   // fChain->SetBranchAddress("EventPlane.fUniqueID", EventPlane_fUniqueID, &b_EventPlane_fUniqueID);
   // fChain->SetBranchAddress("EventPlane.fBits", EventPlane_fBits, &b_EventPlane_fBits);
   // fChain->SetBranchAddress("EventPlane.mQx_eta_pos", EventPlane_mQx_eta_pos, &b_EventPlane_mQx_eta_pos);
   // fChain->SetBranchAddress("EventPlane.mQy_eta_pos", EventPlane_mQy_eta_pos, &b_EventPlane_mQy_eta_pos);
   // fChain->SetBranchAddress("EventPlane.mQx_eta_neg", EventPlane_mQx_eta_neg, &b_EventPlane_mQx_eta_neg);
   // fChain->SetBranchAddress("EventPlane.mQy_eta_neg", EventPlane_mQy_eta_neg, &b_EventPlane_mQy_eta_neg);
   // fChain->SetBranchAddress("EventPlane.mNtrk_eta_pos", EventPlane_mNtrk_eta_pos, &b_EventPlane_mNtrk_eta_pos);
   // fChain->SetBranchAddress("EventPlane.mNtrk_eta_neg", EventPlane_mNtrk_eta_neg, &b_EventPlane_mNtrk_eta_neg);
   // fChain->SetBranchAddress("EventPlane.mWeight_eta_pos", EventPlane_mWeight_eta_pos, &b_EventPlane_mWeight_eta_pos);
   // fChain->SetBranchAddress("EventPlane.mWeight_eta_neg", EventPlane_mWeight_eta_neg, &b_EventPlane_mWeight_eta_neg);
   // fChain->SetBranchAddress("EventPlane.mQx_chg_pos", EventPlane_mQx_chg_pos, &b_EventPlane_mQx_chg_pos);
   // fChain->SetBranchAddress("EventPlane.mQy_chg_pos", EventPlane_mQy_chg_pos, &b_EventPlane_mQy_chg_pos);
   // fChain->SetBranchAddress("EventPlane.mQx_chg_neg", EventPlane_mQx_chg_neg, &b_EventPlane_mQx_chg_neg);
   // fChain->SetBranchAddress("EventPlane.mQy_chg_neg", EventPlane_mQy_chg_neg, &b_EventPlane_mQy_chg_neg);
   // fChain->SetBranchAddress("EventPlane.mNtrk_chg_pos_eta_pos", EventPlane_mNtrk_chg_pos_eta_pos, &b_EventPlane_mNtrk_chg_pos_eta_pos);
   // fChain->SetBranchAddress("EventPlane.mNtrk_chg_pos_eta_neg", EventPlane_mNtrk_chg_pos_eta_neg, &b_EventPlane_mNtrk_chg_pos_eta_neg);
   // fChain->SetBranchAddress("EventPlane.mNtrk_chg_neg_eta_pos", EventPlane_mNtrk_chg_neg_eta_pos, &b_EventPlane_mNtrk_chg_neg_eta_pos);
   // fChain->SetBranchAddress("EventPlane.mNtrk_chg_neg_eta_neg", EventPlane_mNtrk_chg_neg_eta_neg, &b_EventPlane_mNtrk_chg_neg_eta_neg);
   // fChain->SetBranchAddress("EventPlane.mWeight_chg_pos", EventPlane_mWeight_chg_pos, &b_EventPlane_mWeight_chg_pos);
   // fChain->SetBranchAddress("EventPlane.mWeight_chg_neg", EventPlane_mWeight_chg_neg, &b_EventPlane_mWeight_chg_neg);
   // fChain->SetBranchAddress("EventPlane.mQx_ran_1", EventPlane_mQx_ran_1, &b_EventPlane_mQx_ran_1);
   // fChain->SetBranchAddress("EventPlane.mQy_ran_1", EventPlane_mQy_ran_1, &b_EventPlane_mQy_ran_1);
   // fChain->SetBranchAddress("EventPlane.mQx_ran_2", EventPlane_mQx_ran_2, &b_EventPlane_mQx_ran_2);
   // fChain->SetBranchAddress("EventPlane.mQy_ran_2", EventPlane_mQy_ran_2, &b_EventPlane_mQy_ran_2);
   // fChain->SetBranchAddress("EventPlane.mNtrk_ran_1_eta_pos", EventPlane_mNtrk_ran_1_eta_pos, &b_EventPlane_mNtrk_ran_1_eta_pos);
   // fChain->SetBranchAddress("EventPlane.mNtrk_ran_1_eta_neg", EventPlane_mNtrk_ran_1_eta_neg, &b_EventPlane_mNtrk_ran_1_eta_neg);
   // fChain->SetBranchAddress("EventPlane.mNtrk_ran_2_eta_pos", EventPlane_mNtrk_ran_2_eta_pos, &b_EventPlane_mNtrk_ran_2_eta_pos);
   // fChain->SetBranchAddress("EventPlane.mNtrk_ran_2_eta_neg", EventPlane_mNtrk_ran_2_eta_neg, &b_EventPlane_mNtrk_ran_2_eta_neg);
   // fChain->SetBranchAddress("EventPlane.mWeight_ran_1", EventPlane_mWeight_ran_1, &b_EventPlane_mWeight_ran_1);
   // fChain->SetBranchAddress("EventPlane.mWeight_ran_2", EventPlane_mWeight_ran_2, &b_EventPlane_mWeight_ran_2);
   // /***********************************************************************************************/
   // // Tracks
   // fChain->SetBranchAddress("Tracks", &Tracks_, &b_Tracks_);
   // fChain->SetBranchAddress("Tracks.mId", Tracks_mId, &b_Tracks_mId);
   // fChain->SetBranchAddress("Tracks.mChi2", Tracks_mChi2, &b_Tracks_mChi2);
   // fChain->SetBranchAddress("Tracks.mPMomentum.mX1", Tracks_mPMomentum_mX1, &b_Tracks_mPMomentum_mX1);
   // fChain->SetBranchAddress("Tracks.mPMomentum.mX2", Tracks_mPMomentum_mX2, &b_Tracks_mPMomentum_mX2);
   // fChain->SetBranchAddress("Tracks.mPMomentum.mX3", Tracks_mPMomentum_mX3, &b_Tracks_mPMomentum_mX3);
   // fChain->SetBranchAddress("Tracks.mDedx", Tracks_mDedx, &b_Tracks_mDedx);
   // fChain->SetBranchAddress("Tracks.mNHitsFit", Tracks_mNHitsFit, &b_Tracks_mNHitsFit);
   // fChain->SetBranchAddress("Tracks.mNHitsMax", Tracks_mNHitsMax, &b_Tracks_mNHitsMax);
   // fChain->SetBranchAddress("Tracks.mNHitsDedx", Tracks_mNHitsDedx, &b_Tracks_mNHitsDedx);
   // fChain->SetBranchAddress("Tracks.mNSigmaPion", Tracks_mNSigmaPion, &b_Tracks_mNSigmaPion);
   // fChain->SetBranchAddress("Tracks.mNSigmaKaon", Tracks_mNSigmaKaon, &b_Tracks_mNSigmaKaon);
   // fChain->SetBranchAddress("Tracks.mNSigmaProton", Tracks_mNSigmaProton, &b_Tracks_mNSigmaProton);
   // fChain->SetBranchAddress("Tracks.mNSigmaElectron", Tracks_mNSigmaElectron, &b_Tracks_mNSigmaElectron);
   // // fChain->SetBranchAddress("Tracks.mMap0", Tracks_mMap0, &b_Tracks_mMap0);
   // // fChain->SetBranchAddress("Tracks.mMap1", Tracks_mMap1, &b_Tracks_mMap1);
   // // fChain->SetBranchAddress("Tracks.mPar[6]", Tracks_mPar, &b_Tracks_mPar);
   // // fChain->SetBranchAddress("Tracks.mErrMatrix[15]", Tracks_mErrMatrix, &b_Tracks_mErrMatrix);
   // fChain->SetBranchAddress("Tracks.mEmcPidTraitsIndex", Tracks_mEmcPidTraitsIndex, &b_Tracks_mEmcPidTraitsIndex);
   // fChain->SetBranchAddress("Tracks.mBTofPidTraitsIndex", Tracks_mBTofPidTraitsIndex, &b_Tracks_mBTofPidTraitsIndex);
   // fChain->SetBranchAddress("Tracks.mMtdPidTraitsIndex", Tracks_mMtdPidTraitsIndex, &b_Tracks_mMtdPidTraitsIndex);
   // /***********************************************************************************************/
   // // EMcTrigger
   // fChain->SetBranchAddress("EmcTrigger", &EmcTrigger_, &b_EmcTrigger_);
   // fChain->SetBranchAddress("EmcTrigger.fUniqueID", EmcTrigger_fUniqueID, &b_EmcTrigger_fUniqueID);
   // fChain->SetBranchAddress("EmcTrigger.fBits", EmcTrigger_fBits, &b_EmcTrigger_fBits);
   // fChain->SetBranchAddress("EmcTrigger.mFlag", EmcTrigger_mFlag, &b_EmcTrigger_mFlag);
   // fChain->SetBranchAddress("EmcTrigger.mId", EmcTrigger_mId, &b_EmcTrigger_mId);
   // fChain->SetBranchAddress("EmcTrigger.mAdc", EmcTrigger_mAdc, &b_EmcTrigger_mAdc);
   // /***********************************************************************************************/
   // // MtdTrigger
   // fChain->SetBranchAddress("MtdTrigger", &MtdTrigger_, &b_MtdTrigger_);
   // fChain->SetBranchAddress("MtdTrigger.fUniqueID", MtdTrigger_fUniqueID, &b_MtdTrigger_fUniqueID);
   // fChain->SetBranchAddress("MtdTrigger.fBits", MtdTrigger_fBits, &b_MtdTrigger_fBits);
   // fChain->SetBranchAddress("MtdTrigger.mVpdTacSum", MtdTrigger_mVpdTacSum, &b_MtdTrigger_mVpdTacSum);
   // fChain->SetBranchAddress("MtdTrigger.mQTtacSum[4][8]", MtdTrigger_mQTtacSum, &b_MtdTrigger_mQTtacSum);
   // fChain->SetBranchAddress("MtdTrigger.mMT101Tac[4][2]", MtdTrigger_mMT101Tac, &b_MtdTrigger_mMT101Tac);
   // fChain->SetBranchAddress("MtdTrigger.mMT101Id[4][2]", MtdTrigger_mMT101Id, &b_MtdTrigger_mMT101Id);
   // fChain->SetBranchAddress("MtdTrigger.mTF201TriggerBit", MtdTrigger_mTF201TriggerBit, &b_MtdTrigger_mTF201TriggerBit);
   // fChain->SetBranchAddress("MtdTrigger.mShouldHaveRejectEvent", MtdTrigger_mShouldHaveRejectEvent, &b_MtdTrigger_mShouldHaveRejectEvent);

   // fChain->SetBranchAddress("BTOWHit", &BTOWHit_, &b_BTOWHit_);
   // fChain->SetBranchAddress("BTOWHit.fUniqueID", &BTOWHit_fUniqueID, &b_BTOWHit_fUniqueID);
   // fChain->SetBranchAddress("BTOWHit.fBits", &BTOWHit_fBits, &b_BTOWHit_fBits);
   // fChain->SetBranchAddress("BTOWHit.mId", &BTOWHit_mId, &b_BTOWHit_mId);
   // fChain->SetBranchAddress("BTOWHit.mAdc", &BTOWHit_mAdc, &b_BTOWHit_mAdc);
   // fChain->SetBranchAddress("BTOWHit.mE", &BTOWHit_mE, &b_BTOWHit_mE);
   // fChain->SetBranchAddress("BTofHit", &BTofHit_, &b_BTofHit_);
   // fChain->SetBranchAddress("BTofHit.fUniqueID", &BTofHit_fUniqueID, &b_BTofHit_fUniqueID);
   // fChain->SetBranchAddress("BTofHit.fBits", &BTofHit_fBits, &b_BTofHit_fBits);
   // fChain->SetBranchAddress("BTofHit.mId", &BTofHit_mId, &b_BTofHit_mId);
   // fChain->SetBranchAddress("MtdHit", &MtdHit_, &b_MtdHit_);
   // fChain->SetBranchAddress("MtdHit.fUniqueID", MtdHit_fUniqueID, &b_MtdHit_fUniqueID);
   // fChain->SetBranchAddress("MtdHit.fBits", MtdHit_fBits, &b_MtdHit_fBits);
   // fChain->SetBranchAddress("MtdHit.mgChannel", MtdHit_mgChannel, &b_MtdHit_mgChannel);
   // fChain->SetBranchAddress("MtdHit.mTriggerFlag", MtdHit_mTriggerFlag, &b_MtdHit_mTriggerFlag);
   // fChain->SetBranchAddress("MtdHit.mLeadingEdgeTime.first", MtdHit_mLeadingEdgeTime_first, &b_MtdHit_mLeadingEdgeTime_first);
   // fChain->SetBranchAddress("MtdHit.mLeadingEdgeTime.second", MtdHit_mLeadingEdgeTime_second, &b_MtdHit_mLeadingEdgeTime_second);
   // fChain->SetBranchAddress("MtdHit.mTrailingEdgeTime.first", MtdHit_mTrailingEdgeTime_first, &b_MtdHit_mTrailingEdgeTime_first);
   // fChain->SetBranchAddress("MtdHit.mTrailingEdgeTime.second", MtdHit_mTrailingEdgeTime_second, &b_MtdHit_mTrailingEdgeTime_second);
   // /***********************************************************************************************/
   // // EmcPidTraits
   // fChain->SetBranchAddress("EmcPidTraits", &EmcPidTraits_, &b_EmcPidTraits_);
   // fChain->SetBranchAddress("EmcPidTraits.fUniqueID", EmcPidTraits_fUniqueID, &b_EmcPidTraits_fUniqueID);
   // fChain->SetBranchAddress("EmcPidTraits.fBits", EmcPidTraits_fBits, &b_EmcPidTraits_fBits);
   // fChain->SetBranchAddress("EmcPidTraits.mTrackIndex", EmcPidTraits_mTrackIndex, &b_EmcPidTraits_mTrackIndex);
   // fChain->SetBranchAddress("EmcPidTraits.mBEMCId", EmcPidTraits_mBEMCId, &b_EmcPidTraits_mBEMCId);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWADC0", EmcPidTraits_mBTOWADC0, &b_EmcPidTraits_mBTOWADC0);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWE0", EmcPidTraits_mBTOWE0, &b_EmcPidTraits_mBTOWE0);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWE", EmcPidTraits_mBTOWE, &b_EmcPidTraits_mBTOWE);
   // fChain->SetBranchAddress("EmcPidTraits.mBEMCDistZ", EmcPidTraits_mBEMCDistZ, &b_EmcPidTraits_mBEMCDistZ);
   // fChain->SetBranchAddress("EmcPidTraits.mBEMCDistPhi", EmcPidTraits_mBEMCDistPhi, &b_EmcPidTraits_mBEMCDistPhi);
   // fChain->SetBranchAddress("EmcPidTraits.mBSMDNEta", EmcPidTraits_mBSMDNEta, &b_EmcPidTraits_mBSMDNEta);
   // fChain->SetBranchAddress("EmcPidTraits.mBSMDNPhi", EmcPidTraits_mBSMDNPhi, &b_EmcPidTraits_mBSMDNPhi);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWId", EmcPidTraits_mBTOWId, &b_EmcPidTraits_mBTOWId);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWId23", EmcPidTraits_mBTOWId23, &b_EmcPidTraits_mBTOWId23);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWE1", EmcPidTraits_mBTOWE1, &b_EmcPidTraits_mBTOWE1);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWE2", EmcPidTraits_mBTOWE2, &b_EmcPidTraits_mBTOWE2);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWE3", EmcPidTraits_mBTOWE3, &b_EmcPidTraits_mBTOWE3);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWDistEta", EmcPidTraits_mBTOWDistEta, &b_EmcPidTraits_mBTOWDistEta);
   // fChain->SetBranchAddress("EmcPidTraits.mBTOWDistPhi", EmcPidTraits_mBTOWDistPhi, &b_EmcPidTraits_mBTOWDistPhi);
   // /***********************************************************************************************/
   // // BTofPidTraits
   // fChain->SetBranchAddress("BTofPidTraits", &BTofPidTraits_, &b_BTofPidTraits_);
   // fChain->SetBranchAddress("BTofPidTraits.fUniqueID", BTofPidTraits_fUniqueID, &b_BTofPidTraits_fUniqueID);
   // fChain->SetBranchAddress("BTofPidTraits.fBits", BTofPidTraits_fBits, &b_BTofPidTraits_fBits);
   // fChain->SetBranchAddress("BTofPidTraits.mTrackIndex", BTofPidTraits_mTrackIndex, &b_BTofPidTraits_mTrackIndex);
   // fChain->SetBranchAddress("BTofPidTraits.mBTofCellId", BTofPidTraits_mBTofCellId, &b_BTofPidTraits_mBTofCellId);
   // fChain->SetBranchAddress("BTofPidTraits.mBTofMatchFlag", BTofPidTraits_mBTofMatchFlag, &b_BTofPidTraits_mBTofMatchFlag);
   // fChain->SetBranchAddress("BTofPidTraits.mBTof", BTofPidTraits_mBTof, &b_BTofPidTraits_mBTof);
   // fChain->SetBranchAddress("BTofPidTraits.mBTofBeta", BTofPidTraits_mBTofBeta, &b_BTofPidTraits_mBTofBeta);
   // fChain->SetBranchAddress("BTofPidTraits.mBTofYLocal", BTofPidTraits_mBTofYLocal, &b_BTofPidTraits_mBTofYLocal);
   // fChain->SetBranchAddress("BTofPidTraits.mBTofZLocal", BTofPidTraits_mBTofZLocal, &b_BTofPidTraits_mBTofZLocal);
   // fChain->SetBranchAddress("BTofPidTraits.mBTofHitPosX", BTofPidTraits_mBTofHitPosX, &b_BTofPidTraits_mBTofHitPosX);
   // fChain->SetBranchAddress("BTofPidTraits.mBTofHitPosY", BTofPidTraits_mBTofHitPosY, &b_BTofPidTraits_mBTofHitPosY);
   // fChain->SetBranchAddress("BTofPidTraits.mBTofHitPosZ", BTofPidTraits_mBTofHitPosZ, &b_BTofPidTraits_mBTofHitPosZ);
   // /***********************************************************************************************/
   // // MtdPidTraits
   // fChain->SetBranchAddress("MtdPidTraits", &MtdPidTraits_, &b_MtdPidTraits_);
   // fChain->SetBranchAddress("MtdPidTraits.fUniqueID", MtdPidTraits_fUniqueID, &b_MtdPidTraits_fUniqueID);
   // fChain->SetBranchAddress("MtdPidTraits.fBits", MtdPidTraits_fBits, &b_MtdPidTraits_fBits);
   // fChain->SetBranchAddress("MtdPidTraits.mMtdHitChan", MtdPidTraits_mMtdHitChan, &b_MtdPidTraits_mMtdHitChan);
   // fChain->SetBranchAddress("MtdPidTraits.mTrackIndex", MtdPidTraits_mTrackIndex, &b_MtdPidTraits_mTrackIndex);
   // fChain->SetBranchAddress("MtdPidTraits.mMatchFlag", MtdPidTraits_mMatchFlag, &b_MtdPidTraits_mMatchFlag);
   // fChain->SetBranchAddress("MtdPidTraits.mDeltaY", MtdPidTraits_mDeltaY, &b_MtdPidTraits_mDeltaY);
   // fChain->SetBranchAddress("MtdPidTraits.mDeltaZ", MtdPidTraits_mDeltaZ, &b_MtdPidTraits_mDeltaZ);
   // fChain->SetBranchAddress("MtdPidTraits.mDeltaTimeOfFlight", MtdPidTraits_mDeltaTimeOfFlight, &b_MtdPidTraits_mDeltaTimeOfFlight);
   // fChain->SetBranchAddress("MtdPidTraits.mBeta", MtdPidTraits_mBeta, &b_MtdPidTraits_mBeta);
   
   // fChain->SetBranchAddress("V0Ks", &V0Ks_, &b_V0Ks_);
   // fChain->SetBranchAddress("V0Ks.mIndex2Track[2]", &V0Ks_mIndex2Track, &b_V0Ks_mIndex2Track);
   // fChain->SetBranchAddress("V0Ks.mV0Pos.mX1", &V0Ks_mV0Pos_mX1, &b_V0Ks_mV0Pos_mX1);
   // fChain->SetBranchAddress("V0Ks.mV0Pos.mX2", &V0Ks_mV0Pos_mX2, &b_V0Ks_mV0Pos_mX2);
   // fChain->SetBranchAddress("V0Ks.mV0Pos.mX3", &V0Ks_mV0Pos_mX3, &b_V0Ks_mV0Pos_mX3);
   // fChain->SetBranchAddress("V0Ks.mDcaDaughters", &V0Ks_mDcaDaughters, &b_V0Ks_mDcaDaughters);
   // fChain->SetBranchAddress("V0Ks.mDca2Vtx", &V0Ks_mDca2Vtx, &b_V0Ks_mDca2Vtx);
   // fChain->SetBranchAddress("V0Ks.mM", &V0Ks_mM, &b_V0Ks_mM);
   // fChain->SetBranchAddress("V0L", &V0L_, &b_V0L_);
   // fChain->SetBranchAddress("V0L.mIndex2Track[2]", &V0L_mIndex2Track, &b_V0L_mIndex2Track);
   // fChain->SetBranchAddress("V0L.mV0Pos.mX1", &V0L_mV0Pos_mX1, &b_V0L_mV0Pos_mX1);
   // fChain->SetBranchAddress("V0L.mV0Pos.mX2", &V0L_mV0Pos_mX2, &b_V0L_mV0Pos_mX2);
   // fChain->SetBranchAddress("V0L.mV0Pos.mX3", &V0L_mV0Pos_mX3, &b_V0L_mV0Pos_mX3);
   // fChain->SetBranchAddress("V0L.mDcaDaughters", &V0L_mDcaDaughters, &b_V0L_mDcaDaughters);
   // fChain->SetBranchAddress("V0L.mDca2Vtx", &V0L_mDca2Vtx, &b_V0L_mDca2Vtx);
   // fChain->SetBranchAddress("V0L.mM", &V0L_mM, &b_V0L_mM);
   // fChain->SetBranchAddress("V0Lbar", &V0Lbar_, &b_V0Lbar_);
   // fChain->SetBranchAddress("V0Lbar.mIndex2Track[2]", &V0Lbar_mIndex2Track, &b_V0Lbar_mIndex2Track);
   // fChain->SetBranchAddress("V0Lbar.mV0Pos.mX1", &V0Lbar_mV0Pos_mX1, &b_V0Lbar_mV0Pos_mX1);
   // fChain->SetBranchAddress("V0Lbar.mV0Pos.mX2", &V0Lbar_mV0Pos_mX2, &b_V0Lbar_mV0Pos_mX2);
   // fChain->SetBranchAddress("V0Lbar.mV0Pos.mX3", &V0Lbar_mV0Pos_mX3, &b_V0Lbar_mV0Pos_mX3);
   // fChain->SetBranchAddress("V0Lbar.mDcaDaughters", &V0Lbar_mDcaDaughters, &b_V0Lbar_mDcaDaughters);
   // fChain->SetBranchAddress("V0Lbar.mDca2Vtx", &V0Lbar_mDca2Vtx, &b_V0Lbar_mDca2Vtx);
   // fChain->SetBranchAddress("V0Lbar.mM", &V0Lbar_mM, &b_V0Lbar_mM);
   // Notify();
}

Bool_t PicoDstRun14AuAu200::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void PicoDstRun14AuAu200::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t PicoDstRun14AuAu200::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

