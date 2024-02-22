//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb 20 12:50:23 2024 by ROOT version 6.28/04
// from TTree TPC/tree of DstTPCTracking
// found on file: GenfitKpXiPol_0_GenfitXiSearchGeant4.root
//////////////////////////////////////////////////////////

#ifndef TPC_h
#define TPC_h

// Header file for the classes stored in the TTree if any.


// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           status;
   Int_t           evnum;
   Int_t           nhHtof;
   vector<double>  *HtofSeg;
   vector<double>  *tHtof;
   vector<double>  *deHtof;
   vector<double>  *posHtof;
   Int_t           ntTpc;
   vector<int>     *nhtrack;
   vector<int>     *charge;
   vector<int>     *pid;
   vector<double>  *chisqr;
   vector<double>  *helix_cx;
   vector<double>  *helix_cy;
   vector<double>  *helix_z0;
   vector<double>  *helix_r;
   vector<double>  *helix_dz;
   vector<double>  *dE;
   vector<double>  *dEdx;
   vector<double>  *mom0;
   vector<double>  *path;
   vector<vector<double> > *helix_t;
   vector<vector<double> > *resolution_x;
   vector<vector<double> > *resolution_y;
   vector<vector<double> > *resolution_z;
   Int_t           G4kmid;
   Int_t           G4kmtid;
   Double_t        G4kmvtx_x;
   Double_t        G4kmvtx_y;
   Double_t        G4kmvtx_z;
   Double_t        G4kmmom;
   Double_t        G4kmmom_x;
   Double_t        G4kmmom_y;
   Double_t        G4kmmom_z;
   Int_t           G4kpid;
   Int_t           G4kptid;
   Double_t        G4kpvtx_x;
   Double_t        G4kpvtx_y;
   Double_t        G4kpvtx_z;
   Double_t        G4kpmom;
   Double_t        G4kpmom_x;
   Double_t        G4kpmom_y;
   Double_t        G4kpmom_z;
   Int_t           G4xiid;
   Double_t        G4xivtx_x;
   Double_t        G4xivtx_y;
   Double_t        G4xivtx_z;
   Double_t        G4ximom;
   Double_t        G4ximom_x;
   Double_t        G4ximom_y;
   Double_t        G4ximom_z;
   Int_t           G4lid;
   Double_t        G4lvtx_x;
   Double_t        G4lvtx_y;
   Double_t        G4lvtx_z;
   Double_t        G4lmom;
   Double_t        G4lmom_x;
   Double_t        G4lmom_y;
   Double_t        G4lmom_z;
   Int_t           G4pid;
   Int_t           G4ptid;
   Int_t           G4pnh;
   Int_t           G4ptnh;
   Double_t        G4pvtx_x;
   Double_t        G4pvtx_y;
   Double_t        G4pvtx_z;
   Double_t        G4pmom;
   Double_t        G4pmom_x;
   Double_t        G4pmom_y;
   Double_t        G4pmom_z;
   Int_t           ptid;
   Int_t           pnh;
   Double_t        pvtx_x;
   Double_t        pvtx_y;
   Double_t        pvtx_z;
   Double_t        pmom;
   Double_t        pmom_x;
   Double_t        pmom_y;
   Double_t        pmom_z;
   Double_t        GFpmom;
   Double_t        GFpmom_x;
   Double_t        GFpmom_y;
   Double_t        GFpmom_z;
   Int_t           G4pi1id;
   Int_t           G4pi1tid;
   Int_t           G4pi1nh;
   Int_t           G4pi1tnh;
   Double_t        G4pi1vtx_x;
   Double_t        G4pi1vtx_y;
   Double_t        G4pi1vtx_z;
   Double_t        G4pi1mom;
   Double_t        G4pi1mom_x;
   Double_t        G4pi1mom_y;
   Double_t        G4pi1mom_z;
   Int_t           pi1tid;
   Int_t           pi1nh;
   Double_t        pi1vtx_x;
   Double_t        pi1vtx_y;
   Double_t        pi1vtx_z;
   Double_t        pi1mom;
   Double_t        pi1mom_x;
   Double_t        pi1mom_y;
   Double_t        pi1mom_z;
   Double_t        GFpi1mom;
   Double_t        GFpi1mom_x;
   Double_t        GFpi1mom_y;
   Double_t        GFpi1mom_z;
   Int_t           G4pi2id;
   Int_t           G4pi2tid;
   Int_t           G4pi2nh;
   Int_t           G4pi2tnh;
   Double_t        G4pi2vtx_x;
   Double_t        G4pi2vtx_y;
   Double_t        G4pi2vtx_z;
   Double_t        G4pi2mom;
   Double_t        G4pi2mom_x;
   Double_t        G4pi2mom_y;
   Double_t        G4pi2mom_z;
   Int_t           pi2tid;
   Int_t           pi2nh;
   Double_t        pi2vtx_x;
   Double_t        pi2vtx_y;
   Double_t        pi2vtx_z;
   Double_t        pi2mom;
   Double_t        pi2mom_x;
   Double_t        pi2mom_y;
   Double_t        pi2mom_z;
   Double_t        GFpi2mom;
   Double_t        GFpi2mom_x;
   Double_t        GFpi2mom_y;
   Double_t        GFpi2mom_z;
   Bool_t          Lflag;
   Bool_t          Xiflag;
   Double_t        XiMass;
   Double_t        XiDecayVtx_x;
   Double_t        XiDecayVtx_y;
   Double_t        XiDecayVtx_z;
   Double_t        XiMom_x;
   Double_t        XiMom_y;
   Double_t        XiMom_z;
   Double_t        XiVtxCloseDist;
   Double_t        LambdaMass;
   Double_t        LambdaDecayVtx_x;
   Double_t        LambdaDecayVtx_y;
   Double_t        LambdaDecayVtx_z;
   Double_t        LambdaMom_x;
   Double_t        LambdaMom_y;
   Double_t        LambdaMom_z;
   Double_t        LambdaVtxCloseDist;
   Bool_t          GFXiflag;
   Double_t        GFXiMass;
   Double_t        GFXiDecayVtx_x;
   Double_t        GFXiDecayVtx_y;
   Double_t        GFXiDecayVtx_z;
   Double_t        GFXiMom_x;
   Double_t        GFXiMom_y;
   Double_t        GFXiMom_z;
   Double_t        GFXiVtxCloseDist;
   Double_t        GFLambdaMass;
   Double_t        GFLambdaDecayVtx_x;
   Double_t        GFLambdaDecayVtx_y;
   Double_t        GFLambdaDecayVtx_z;
   Double_t        GFLambdaMom_x;
   Double_t        GFLambdaMom_y;
   Double_t        GFLambdaMom_z;
   Double_t        GFLambdaVtxCloseDist;
   Int_t           GFstatus;
   Int_t           GFntTpc;
   // List of branches
   TBranch        *b_status;   //!
   TBranch        *b_evnum;   //!
   TBranch        *b_nhHtof;   //!
   TBranch        *b_HtofSeg;   //!
   TBranch        *b_tHtof;   //!
   TBranch        *b_deHtof;   //!
   TBranch        *b_posHtof;   //!
   TBranch        *b_ntTpc;   //!
   TBranch        *b_nhtrack;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_pid;   //!
   TBranch        *b_chisqr;   //!
   TBranch        *b_helix_cx;   //!
   TBranch        *b_helix_cy;   //!
   TBranch        *b_helix_z0;   //!
   TBranch        *b_helix_r;   //!
   TBranch        *b_helix_dz;   //!
   TBranch        *b_dE;   //!
   TBranch        *b_dEdx;   //!
   TBranch        *b_mom0;   //!
   TBranch        *b_path;   //!
   TBranch        *b_helix_t;   //!
   TBranch        *b_resolution_x;   //!
   TBranch        *b_resolution_y;   //!
   TBranch        *b_resolution_z;   //!
   TBranch        *b_G4kmid;   //!
   TBranch        *b_G4kmtid;   //!
   TBranch        *b_G4kmvtx_x;   //!
   TBranch        *b_G4kmvtx_y;   //!
   TBranch        *b_G4kmvtx_z;   //!
   TBranch        *b_G4kmmom;   //!
   TBranch        *b_G4kmmom_x;   //!
   TBranch        *b_G4kmmom_y;   //!
   TBranch        *b_G4kmmom_z;   //!
   TBranch        *b_G4kpid;   //!
   TBranch        *b_G4kptid;   //!
   TBranch        *b_G4kpvtx_x;   //!
   TBranch        *b_G4kpvtx_y;   //!
   TBranch        *b_G4kpvtx_z;   //!
   TBranch        *b_G4kpmom;   //!
   TBranch        *b_G4kpmom_x;   //!
   TBranch        *b_G4kpmom_y;   //!
   TBranch        *b_G4kpmom_z;   //!
   TBranch        *b_G4xiid;   //!
   TBranch        *b_G4xivtx_x;   //!
   TBranch        *b_G4xivtx_y;   //!
   TBranch        *b_G4xivtx_z;   //!
   TBranch        *b_G4ximom;   //!
   TBranch        *b_G4ximom_x;   //!
   TBranch        *b_G4ximom_y;   //!
   TBranch        *b_G4ximom_z;   //!
   TBranch        *b_G4lid;   //!
   TBranch        *b_G4lvtx_x;   //!
   TBranch        *b_G4lvtx_y;   //!
   TBranch        *b_G4lvtx_z;   //!
   TBranch        *b_G4lmom;   //!
   TBranch        *b_G4lmom_x;   //!
   TBranch        *b_G4lmom_y;   //!
   TBranch        *b_G4lmom_z;   //!
   TBranch        *b_G4pid;   //!
   TBranch        *b_G4ptid;   //!
   TBranch        *b_G4pnh;   //!
   TBranch        *b_G4ptnh;   //!
   TBranch        *b_G4pvtx_x;   //!
   TBranch        *b_G4pvtx_y;   //!
   TBranch        *b_G4pvtx_z;   //!
   TBranch        *b_G4pmom;   //!
   TBranch        *b_G4pmom_x;   //!
   TBranch        *b_G4pmom_y;   //!
   TBranch        *b_G4pmom_z;   //!
   TBranch        *b_ptid;   //!
   TBranch        *b_pnh;   //!
   TBranch        *b_pvtx_x;   //!
   TBranch        *b_pvtx_y;   //!
   TBranch        *b_pvtx_z;   //!
   TBranch        *b_pmom;   //!
   TBranch        *b_pmom_x;   //!
   TBranch        *b_pmom_y;   //!
   TBranch        *b_pmom_z;   //!
   TBranch        *b_GFpmom;   //!
   TBranch        *b_GFpmom_x;   //!
   TBranch        *b_GFpmom_y;   //!
   TBranch        *b_GFpmom_z;   //!
   TBranch        *b_G4pi1id;   //!
   TBranch        *b_G4pi1tid;   //!
   TBranch        *b_G4pi1nh;   //!
   TBranch        *b_G4pi1tnh;   //!
   TBranch        *b_G4pi1vtx_x;   //!
   TBranch        *b_G4pi1vtx_y;   //!
   TBranch        *b_G4pi1vtx_z;   //!
   TBranch        *b_G4pi1mom;   //!
   TBranch        *b_G4pi1mom_x;   //!
   TBranch        *b_G4pi1mom_y;   //!
   TBranch        *b_G4pi1mom_z;   //!
   TBranch        *b_pi1tid;   //!
   TBranch        *b_pi1nh;   //!
   TBranch        *b_pi1vtx_x;   //!
   TBranch        *b_pi1vtx_y;   //!
   TBranch        *b_pi1vtx_z;   //!
   TBranch        *b_pi1mom;   //!
   TBranch        *b_pi1mom_x;   //!
   TBranch        *b_pi1mom_y;   //!
   TBranch        *b_pi1mom_z;   //!
   TBranch        *b_GFpi1mom;   //!
   TBranch        *b_GFpi1mom_x;   //!
   TBranch        *b_GFpi1mom_y;   //!
   TBranch        *b_GFpi1mom_z;   //!
   TBranch        *b_G4pi2id;   //!
   TBranch        *b_G4pi2tid;   //!
   TBranch        *b_G4pi2nh;   //!
   TBranch        *b_G4pi2tnh;   //!
   TBranch        *b_G4pi2vtx_x;   //!
   TBranch        *b_G4pi2vtx_y;   //!
   TBranch        *b_G4pi2vtx_z;   //!
   TBranch        *b_G4pi2mom;   //!
   TBranch        *b_G4pi2mom_x;   //!
   TBranch        *b_G4pi2mom_y;   //!
   TBranch        *b_G4pi2mom_z;   //!
   TBranch        *b_pi2tid;   //!
   TBranch        *b_pi2nh;   //!
   TBranch        *b_pi2vtx_x;   //!
   TBranch        *b_pi2vtx_y;   //!
   TBranch        *b_pi2vtx_z;   //!
   TBranch        *b_pi2mom;   //!
   TBranch        *b_pi2mom_x;   //!
   TBranch        *b_pi2mom_y;   //!
   TBranch        *b_pi2mom_z;   //!
   TBranch        *b_GFpi2mom;   //!
   TBranch        *b_GFpi2mom_x;   //!
   TBranch        *b_GFpi2mom_y;   //!
   TBranch        *b_GFpi2mom_z;   //!
   TBranch        *b_Lflag;   //!
   TBranch        *b_Xiflag;   //!
   TBranch        *b_XiMass;   //!
   TBranch        *b_XiDecayVtx_x;   //!
   TBranch        *b_XiDecayVtx_y;   //!
   TBranch        *b_XiDecayVtx_z;   //!
   TBranch        *b_XiMom_x;   //!
   TBranch        *b_XiMom_y;   //!
   TBranch        *b_XiMom_z;   //!
   TBranch        *b_XiVtxCloseDist;   //!
   TBranch        *b_LambdaMass;   //!
   TBranch        *b_LambdaDecayVtx_x;   //!
   TBranch        *b_LambdaDecayVtx_y;   //!
   TBranch        *b_LambdaDecayVtx_z;   //!
   TBranch        *b_LambdaMom_x;   //!
   TBranch        *b_LambdaMom_y;   //!
   TBranch        *b_LambdaMom_z;   //!
   TBranch        *b_LambdaVtxCloseDist;   //!
   TBranch        *b_DecaysTrackId;   //!
   TBranch        *b_DecaysMom;   //!
   TBranch        *b_GFXiflag;   //!
   TBranch        *b_GFXiMass;   //!
   TBranch        *b_GFXiDecayVtx_x;   //!
   TBranch        *b_GFXiDecayVtx_y;   //!
   TBranch        *b_GFXiDecayVtx_z;   //!
   TBranch        *b_GFXiMom_x;   //!
   TBranch        *b_GFXiMom_y;   //!
   TBranch        *b_GFXiMom_z;   //!
   TBranch        *b_GFXiVtxCloseDist;   //!
   TBranch        *b_GFLambdaMass;   //!
   TBranch        *b_GFLambdaDecayVtx_x;   //!
   TBranch        *b_GFLambdaDecayVtx_y;   //!
   TBranch        *b_GFLambdaDecayVtx_z;   //!
   TBranch        *b_GFLambdaMom_x;   //!
   TBranch        *b_GFLambdaMom_y;   //!
   TBranch        *b_GFLambdaMom_z;   //!
   TBranch        *b_GFLambdaVtxCloseDist;   //!
   TBranch        *b_GFDecaysMass;   //!
   TBranch        *b_GFDecaysMom;   //!
   TBranch        *b_GFDecaysMom_x;   //!
   TBranch        *b_GFDecaysMom_y;   //!
   TBranch        *b_GFDecaysMom_z;   //!
   TBranch        *b_GFMomLoss;   //!
   TBranch        *b_GFELoss;   //!
   TBranch        *b_GFstatus;   //!
   TBranch        *b_GFntTpc;   //!
   TBranch        *b_GFcharge;   //!
   TBranch        *b_GFchisqr;   //!
   TBranch        *b_GFtof;   //!
   TBranch        *b_GFtracklen;   //!
   TBranch        *b_GFpval;   //!
   TBranch        *b_GFfitstatus;   //!
   TBranch        *b_GFpdgcode;   //!
   TBranch        *b_GFnhtrack;   //!
   TBranch        *b_GFlayer;   //!
   TBranch        *b_GFpos_x;   //!
   TBranch        *b_GFpos_y;   //!
   TBranch        *b_GFpos_z;   //!
   TBranch        *b_GFmom;   //!
   TBranch        *b_GFmom_x;   //!
   TBranch        *b_GFmom_y;   //!
   TBranch        *b_GFmom_z;   //!
   TBranch        *b_GFresidual_x;   //!
   TBranch        *b_GFresidual_y;   //!
   TBranch        *b_GFresidual_z;   //!
   TBranch        *b_GFresidual_p;   //!
   TBranch        *b_GFresidual_px;   //!
   TBranch        *b_GFresidual_py;   //!
   TBranch        *b_GFresidual_pz;   //!

	void InitTree(TTree* tree);



void
InitTree(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   HtofSeg = 0;
   tHtof = 0;
   deHtof = 0;
   posHtof = 0;
   nhtrack = 0;
   charge = 0;
   pid = 0;
   chisqr = 0;
   helix_cx = 0;
   helix_cy = 0;
   helix_z0 = 0;
   helix_r = 0;
   helix_dz = 0;
   dE = 0;
   dEdx = 0;
   mom0 = 0;
   path = 0;
   helix_t = 0;
   resolution_x = 0;
   resolution_y = 0;
   resolution_z = 0;
   // Set branch addresses and branch pointers

   tree->SetBranchAddress("status", &status, &b_status);
   tree->SetBranchAddress("evnum", &evnum, &b_evnum);
   tree->SetBranchAddress("nhHtof", &nhHtof, &b_nhHtof);
   tree->SetBranchAddress("HtofSeg", &HtofSeg, &b_HtofSeg);
   tree->SetBranchAddress("tHtof", &tHtof, &b_tHtof);
   tree->SetBranchAddress("deHtof", &deHtof, &b_deHtof);
   tree->SetBranchAddress("posHtof", &posHtof, &b_posHtof);
   tree->SetBranchAddress("ntTpc", &ntTpc, &b_ntTpc);
   tree->SetBranchAddress("nhtrack", &nhtrack, &b_nhtrack);
   tree->SetBranchAddress("charge", &charge, &b_charge);
   tree->SetBranchAddress("pid", &pid, &b_pid);
   tree->SetBranchAddress("chisqr", &chisqr, &b_chisqr);
   tree->SetBranchAddress("helix_cx", &helix_cx, &b_helix_cx);
   tree->SetBranchAddress("helix_cy", &helix_cy, &b_helix_cy);
   tree->SetBranchAddress("helix_z0", &helix_z0, &b_helix_z0);
   tree->SetBranchAddress("helix_r", &helix_r, &b_helix_r);
   tree->SetBranchAddress("helix_dz", &helix_dz, &b_helix_dz);
   tree->SetBranchAddress("dE", &dE, &b_dE);
   tree->SetBranchAddress("dEdx", &dEdx, &b_dEdx);
   tree->SetBranchAddress("mom0", &mom0, &b_mom0);
   tree->SetBranchAddress("path", &path, &b_path);
   tree->SetBranchAddress("helix_t", &helix_t, &b_helix_t);
   tree->SetBranchAddress("resolution_x", &resolution_x, &b_resolution_x);
   tree->SetBranchAddress("resolution_y", &resolution_y, &b_resolution_y);
   tree->SetBranchAddress("resolution_z", &resolution_z, &b_resolution_z);
   tree->SetBranchAddress("G4kmid", &G4kmid, &b_G4kmid);
   tree->SetBranchAddress("G4kmtid", &G4kmtid, &b_G4kmtid);
   tree->SetBranchAddress("G4kmvtx_x", &G4kmvtx_x, &b_G4kmvtx_x);
   tree->SetBranchAddress("G4kmvtx_y", &G4kmvtx_y, &b_G4kmvtx_y);
   tree->SetBranchAddress("G4kmvtx_z", &G4kmvtx_z, &b_G4kmvtx_z);
   tree->SetBranchAddress("G4kmmom", &G4kmmom, &b_G4kmmom);
   tree->SetBranchAddress("G4kmmom_x", &G4kmmom_x, &b_G4kmmom_x);
   tree->SetBranchAddress("G4kmmom_y", &G4kmmom_y, &b_G4kmmom_y);
   tree->SetBranchAddress("G4kmmom_z", &G4kmmom_z, &b_G4kmmom_z);
   tree->SetBranchAddress("G4kpid", &G4kpid, &b_G4kpid);
   tree->SetBranchAddress("G4kptid", &G4kptid, &b_G4kptid);
   tree->SetBranchAddress("G4kpvtx_x", &G4kpvtx_x, &b_G4kpvtx_x);
   tree->SetBranchAddress("G4kpvtx_y", &G4kpvtx_y, &b_G4kpvtx_y);
   tree->SetBranchAddress("G4kpvtx_z", &G4kpvtx_z, &b_G4kpvtx_z);
   tree->SetBranchAddress("G4kpmom", &G4kpmom, &b_G4kpmom);
   tree->SetBranchAddress("G4kpmom_x", &G4kpmom_x, &b_G4kpmom_x);
   tree->SetBranchAddress("G4kpmom_y", &G4kpmom_y, &b_G4kpmom_y);
   tree->SetBranchAddress("G4kpmom_z", &G4kpmom_z, &b_G4kpmom_z);
   tree->SetBranchAddress("G4xiid", &G4xiid, &b_G4xiid);
   tree->SetBranchAddress("G4xivtx_x", &G4xivtx_x, &b_G4xivtx_x);
   tree->SetBranchAddress("G4xivtx_y", &G4xivtx_y, &b_G4xivtx_y);
   tree->SetBranchAddress("G4xivtx_z", &G4xivtx_z, &b_G4xivtx_z);
   tree->SetBranchAddress("G4ximom", &G4ximom, &b_G4ximom);
   tree->SetBranchAddress("G4ximom_x", &G4ximom_x, &b_G4ximom_x);
   tree->SetBranchAddress("G4ximom_y", &G4ximom_y, &b_G4ximom_y);
   tree->SetBranchAddress("G4ximom_z", &G4ximom_z, &b_G4ximom_z);
   tree->SetBranchAddress("G4lid", &G4lid, &b_G4lid);
   tree->SetBranchAddress("G4lvtx_x", &G4lvtx_x, &b_G4lvtx_x);
   tree->SetBranchAddress("G4lvtx_y", &G4lvtx_y, &b_G4lvtx_y);
   tree->SetBranchAddress("G4lvtx_z", &G4lvtx_z, &b_G4lvtx_z);
   tree->SetBranchAddress("G4lmom", &G4lmom, &b_G4lmom);
   tree->SetBranchAddress("G4lmom_x", &G4lmom_x, &b_G4lmom_x);
   tree->SetBranchAddress("G4lmom_y", &G4lmom_y, &b_G4lmom_y);
   tree->SetBranchAddress("G4lmom_z", &G4lmom_z, &b_G4lmom_z);
   tree->SetBranchAddress("G4pid", &G4pid, &b_G4pid);
   tree->SetBranchAddress("G4ptid", &G4ptid, &b_G4ptid);
   tree->SetBranchAddress("G4pnh", &G4pnh, &b_G4pnh);
   tree->SetBranchAddress("G4ptnh", &G4ptnh, &b_G4ptnh);
   tree->SetBranchAddress("G4pvtx_x", &G4pvtx_x, &b_G4pvtx_x);
   tree->SetBranchAddress("G4pvtx_y", &G4pvtx_y, &b_G4pvtx_y);
   tree->SetBranchAddress("G4pvtx_z", &G4pvtx_z, &b_G4pvtx_z);
   tree->SetBranchAddress("G4pmom", &G4pmom, &b_G4pmom);
   tree->SetBranchAddress("G4pmom_x", &G4pmom_x, &b_G4pmom_x);
   tree->SetBranchAddress("G4pmom_y", &G4pmom_y, &b_G4pmom_y);
   tree->SetBranchAddress("G4pmom_z", &G4pmom_z, &b_G4pmom_z);
   tree->SetBranchAddress("ptid", &ptid, &b_ptid);
   tree->SetBranchAddress("pnh", &pnh, &b_pnh);
   tree->SetBranchAddress("pvtx_x", &pvtx_x, &b_pvtx_x);
   tree->SetBranchAddress("pvtx_y", &pvtx_y, &b_pvtx_y);
   tree->SetBranchAddress("pvtx_z", &pvtx_z, &b_pvtx_z);
   tree->SetBranchAddress("pmom", &pmom, &b_pmom);
   tree->SetBranchAddress("pmom_x", &pmom_x, &b_pmom_x);
   tree->SetBranchAddress("pmom_y", &pmom_y, &b_pmom_y);
   tree->SetBranchAddress("pmom_z", &pmom_z, &b_pmom_z);
   tree->SetBranchAddress("GFpmom", &GFpmom, &b_GFpmom);
   tree->SetBranchAddress("GFpmom_x", &GFpmom_x, &b_GFpmom_x);
   tree->SetBranchAddress("GFpmom_y", &GFpmom_y, &b_GFpmom_y);
   tree->SetBranchAddress("GFpmom_z", &GFpmom_z, &b_GFpmom_z);
   tree->SetBranchAddress("G4pi1id", &G4pi1id, &b_G4pi1id);
   tree->SetBranchAddress("G4pi1tid", &G4pi1tid, &b_G4pi1tid);
   tree->SetBranchAddress("G4pi1nh", &G4pi1nh, &b_G4pi1nh);
   tree->SetBranchAddress("G4pi1tnh", &G4pi1tnh, &b_G4pi1tnh);
   tree->SetBranchAddress("G4pi1vtx_x", &G4pi1vtx_x, &b_G4pi1vtx_x);
   tree->SetBranchAddress("G4pi1vtx_y", &G4pi1vtx_y, &b_G4pi1vtx_y);
   tree->SetBranchAddress("G4pi1vtx_z", &G4pi1vtx_z, &b_G4pi1vtx_z);
   tree->SetBranchAddress("G4pi1mom", &G4pi1mom, &b_G4pi1mom);
   tree->SetBranchAddress("G4pi1mom_x", &G4pi1mom_x, &b_G4pi1mom_x);
   tree->SetBranchAddress("G4pi1mom_y", &G4pi1mom_y, &b_G4pi1mom_y);
   tree->SetBranchAddress("G4pi1mom_z", &G4pi1mom_z, &b_G4pi1mom_z);
   tree->SetBranchAddress("pi1tid", &pi1tid, &b_pi1tid);
   tree->SetBranchAddress("pi1nh", &pi1nh, &b_pi1nh);
   tree->SetBranchAddress("pi1vtx_x", &pi1vtx_x, &b_pi1vtx_x);
   tree->SetBranchAddress("pi1vtx_y", &pi1vtx_y, &b_pi1vtx_y);
   tree->SetBranchAddress("pi1vtx_z", &pi1vtx_z, &b_pi1vtx_z);
   tree->SetBranchAddress("pi1mom", &pi1mom, &b_pi1mom);
   tree->SetBranchAddress("pi1mom_x", &pi1mom_x, &b_pi1mom_x);
   tree->SetBranchAddress("pi1mom_y", &pi1mom_y, &b_pi1mom_y);
   tree->SetBranchAddress("pi1mom_z", &pi1mom_z, &b_pi1mom_z);
   tree->SetBranchAddress("GFpi1mom", &GFpi1mom, &b_GFpi1mom);
   tree->SetBranchAddress("GFpi1mom_x", &GFpi1mom_x, &b_GFpi1mom_x);
   tree->SetBranchAddress("GFpi1mom_y", &GFpi1mom_y, &b_GFpi1mom_y);
   tree->SetBranchAddress("GFpi1mom_z", &GFpi1mom_z, &b_GFpi1mom_z);
   tree->SetBranchAddress("G4pi2id", &G4pi2id, &b_G4pi2id);
   tree->SetBranchAddress("G4pi2tid", &G4pi2tid, &b_G4pi2tid);
   tree->SetBranchAddress("G4pi2nh", &G4pi2nh, &b_G4pi2nh);
   tree->SetBranchAddress("G4pi2tnh", &G4pi2tnh, &b_G4pi2tnh);
   tree->SetBranchAddress("G4pi2vtx_x", &G4pi2vtx_x, &b_G4pi2vtx_x);
   tree->SetBranchAddress("G4pi2vtx_y", &G4pi2vtx_y, &b_G4pi2vtx_y);
   tree->SetBranchAddress("G4pi2vtx_z", &G4pi2vtx_z, &b_G4pi2vtx_z);
   tree->SetBranchAddress("G4pi2mom", &G4pi2mom, &b_G4pi2mom);
   tree->SetBranchAddress("G4pi2mom_x", &G4pi2mom_x, &b_G4pi2mom_x);
   tree->SetBranchAddress("G4pi2mom_y", &G4pi2mom_y, &b_G4pi2mom_y);
   tree->SetBranchAddress("G4pi2mom_z", &G4pi2mom_z, &b_G4pi2mom_z);
   tree->SetBranchAddress("pi2tid", &pi2tid, &b_pi2tid);
   tree->SetBranchAddress("pi2nh", &pi2nh, &b_pi2nh);
   tree->SetBranchAddress("pi2vtx_x", &pi2vtx_x, &b_pi2vtx_x);
   tree->SetBranchAddress("pi2vtx_y", &pi2vtx_y, &b_pi2vtx_y);
   tree->SetBranchAddress("pi2vtx_z", &pi2vtx_z, &b_pi2vtx_z);
   tree->SetBranchAddress("pi2mom", &pi2mom, &b_pi2mom);
   tree->SetBranchAddress("pi2mom_x", &pi2mom_x, &b_pi2mom_x);
   tree->SetBranchAddress("pi2mom_y", &pi2mom_y, &b_pi2mom_y);
   tree->SetBranchAddress("pi2mom_z", &pi2mom_z, &b_pi2mom_z);
   tree->SetBranchAddress("GFpi2mom", &GFpi2mom, &b_GFpi2mom);
   tree->SetBranchAddress("GFpi2mom_x", &GFpi2mom_x, &b_GFpi2mom_x);
   tree->SetBranchAddress("GFpi2mom_y", &GFpi2mom_y, &b_GFpi2mom_y);
   tree->SetBranchAddress("GFpi2mom_z", &GFpi2mom_z, &b_GFpi2mom_z);
   tree->SetBranchAddress("Lflag", &Lflag, &b_Lflag);
//   tree->SetBranchAddress("Xiflag", &Xiflag, &b_Xiflag);
   tree->SetBranchAddress("Xiflag", &Xiflag);
   tree->SetBranchAddress("XiMass", &XiMass, &b_XiMass);
   tree->SetBranchAddress("XiDecayVtx_x", &XiDecayVtx_x, &b_XiDecayVtx_x);
   tree->SetBranchAddress("XiDecayVtx_y", &XiDecayVtx_y, &b_XiDecayVtx_y);
   tree->SetBranchAddress("XiDecayVtx_z", &XiDecayVtx_z, &b_XiDecayVtx_z);
   tree->SetBranchAddress("XiMom_x", &XiMom_x, &b_XiMom_x);
   tree->SetBranchAddress("XiMom_y", &XiMom_y, &b_XiMom_y);
   tree->SetBranchAddress("XiMom_z", &XiMom_z, &b_XiMom_z);
   tree->SetBranchAddress("XiVtxCloseDist", &XiVtxCloseDist, &b_XiVtxCloseDist);
   tree->SetBranchAddress("LambdaMass", &LambdaMass, &b_LambdaMass);
   tree->SetBranchAddress("LambdaDecayVtx_x", &LambdaDecayVtx_x, &b_LambdaDecayVtx_x);
   tree->SetBranchAddress("LambdaDecayVtx_y", &LambdaDecayVtx_y, &b_LambdaDecayVtx_y);
   tree->SetBranchAddress("LambdaDecayVtx_z", &LambdaDecayVtx_z, &b_LambdaDecayVtx_z);
   tree->SetBranchAddress("LambdaMom_x", &LambdaMom_x, &b_LambdaMom_x);
   tree->SetBranchAddress("LambdaMom_y", &LambdaMom_y, &b_LambdaMom_y);
   tree->SetBranchAddress("LambdaMom_z", &LambdaMom_z, &b_LambdaMom_z);
   tree->SetBranchAddress("LambdaVtxCloseDist", &LambdaVtxCloseDist, &b_LambdaVtxCloseDist);
}

#endif
