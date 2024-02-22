#include "Dir.hh"
#include "G4XiBranch.hh"
#include "./KpXiPol/tpc.h"
#include "HistG4Xi.hh"
#include "PolarizationAnal.hh"
void G4XiAnal(){
	double pol = 0;
	int scale = 1.;
	int Check = 100;
	double Conf_cut = 0.05;
	TString dir = "./KpXiPol/";
	TString filename = Form("KpXiPol_%g_GenfitXiSearchGeant4.root",pol);
	TFile* file = new TFile(dir+filename);
	TTree* tree = (TTree*)file->Get("tpc");
//	TPC TPCTree(tree);
	InitTree(tree);
	int ent = tree->GetEntries();
	SetStyle();
	gStyle->SetOptTitle(1);
	gStyle->SetOptStat(1110);
	int ndfLd,ndfXi;
	for(int i=0;i<ent*1./scale;++i){
		tree->GetEntry(i);
		if(i%Check == 0) cout<<"Event "<<i<<endl; 
//		if(i%scale != 0) continue; 
		TVector3 G4Vkm(G4kmmom_x,G4kmmom_y,G4kmmom_z);
		TVector3 G4Vkp(G4kpmom_x,G4kpmom_y,G4kpmom_z);
		TVector3 G4Vxi_prod(G4ximom_x,G4ximom_y,G4ximom_z);
		TVector3 G4Vxi_decay(G4lmom_x+G4pi2mom_x,G4lmom_y+G4pi2mom_y,G4lmom_z+G4pi2mom_z);

		TVector3 G4Vl_prod(G4lmom_x,G4lmom_y,G4lmom_z);
		TVector3 G4Vl_decay(G4pmom_x+G4pi1mom_x,G4pmom_y+G4pi1mom_y,G4pmom_z+G4pi1mom_z);
		TVector3 G4Vp(G4pmom_x,G4pmom_y,G4pmom_z);
		TVector3 G4Vpi1(G4pi1mom_x,G4pi1mom_y,G4pi1mom_z);
		TVector3 G4Vpi2(G4pi2mom_x,G4pi2mom_y,G4pi2mom_z);
		
	
		TVector3 Vxi(XiMom_x,XiMom_y,XiMom_z);

		TVector3 Vl(LambdaMom_x,LambdaMom_y,LambdaMom_z);

		TVector3 Vp(pmom_x,pmom_y,pmom_z);
		TVector3 Vpi1(pi1mom_x,pi1mom_y,pi1mom_z);
		TVector3 Vpi2(pi2mom_x,pi2mom_y,pi2mom_z);

		TLorentzVector G4LVp(G4Vp,hypot(mp,G4pmom));
		TLorentzVector G4LVpi1(G4Vpi1,hypot(mpi,G4pi1mom));
		TLorentzVector G4LVpi2(G4Vpi2,hypot(mpi,G4pi2mom));
		TLorentzVector LVp(Vp,hypot(mp,pmom));
		TLorentzVector LVpi1(Vpi1,hypot(mpi,pi1mom));
		TLorentzVector LVpi2(Vpi2,hypot(mpi,pi2mom));

		TVector3 G4XiProdVtx(G4xivtx_x,G4xivtx_y,G4xivtx_z);
		TVector3 G4XiDecayVtx(G4lvtx_x,G4lvtx_y,G4lvtx_z);
		auto G4LdProdVtx = G4XiDecayVtx;
		TVector3 G4LdDecayVtx(G4pvtx_x,G4pvtx_y,G4pvtx_z);

		TVector3 XiDecayVtx(XiDecayVtx_x,XiDecayVtx_y,XiDecayVtx_z);
		TVector3 LdDecayVtx(LambdaDecayVtx_x,LambdaDecayVtx_y,LambdaDecayVtx_z);
		if(!Xiflag) continue;

//Resolutions and Residuals
		auto pres_x = resolution_x->at(ptid);	
		auto pres_y = resolution_y->at(ptid);	
		auto pres_z = resolution_z->at(ptid);	
		auto pi1res_x = resolution_x->at(pi1tid);	
		auto pi1res_y = resolution_y->at(pi1tid);	
		auto pi1res_z = resolution_z->at(pi1tid);	
		auto pi2res_x = resolution_x->at(pi2tid);	
		auto pi2res_y = resolution_y->at(pi2tid);	
		auto pi2res_z = resolution_z->at(pi2tid);	
		
		G4Ldmom = G4Vl_decay.Mag();
		G4Ldmom_x = G4pmom_x+G4pi1mom_x;
		G4Ldmom_y = G4pmom_y+G4pi1mom_y;
		G4Ldmom_z = G4pmom_z+G4pi1mom_z;
		G4Ldmom_t = hypot(G4Ldmom_x,G4Ldmom_z);
		G4LdPh = atan2(G4Ldmom_x,G4Ldmom_z);
		G4LdTh = acos(G4Ldmom_y/G4Ldmom);

		Ldmom = Vl.Mag();
		Ldmom_x = pmom_x+pi1mom_x;
		Ldmom_y = pmom_y+pi1mom_y;
		Ldmom_z = pmom_z+pi1mom_z;
		Ldmom_t = hypot(Ldmom_x,Ldmom_z);
		LdPh = atan2(Ldmom_x,Ldmom_z);
		LdTh = acos(Ldmom_y/Ldmom);

		G4pmom_t = hypot(G4pmom_x,G4pmom_z);
		G4pi1mom_t = hypot(G4pi1mom_x,G4pi1mom_z);
		G4pi2mom_t = hypot(G4pi2mom_x,G4pi2mom_z);
		pmom_t = hypot(pmom_x,pmom_z);
		pi1mom_t = hypot(pi1mom_x,pi1mom_z);
		pi2mom_t = hypot(pi2mom_x,pi2mom_z);
		vector<double>pres_t;
		for(int ih=0;ih<pres_x.size();++ih){
			pres_t.push_back(hypot(pres_x.at(ih),pres_z.at(ih)));
			double t_min = helix_t->at(ptid).at(0);
			double t_max = helix_t->at(ptid).at(pres_x.size()-1);
			double dt = t_max - t_min;
			if(dt > 2*acos(-1)) dt = 2*acos(-1);
			ppath = dt* helix_r->at(ptid);
		}
		vector<double>pi1res_t;
		for(int ih=0;ih<pi1res_x.size();++ih){
			pi1res_t.push_back(hypot(pi1res_x.at(ih),pi1res_z.at(ih)));
			double t_min = helix_t->at(ptid).at(0);
			double t_max = helix_t->at(ptid).at(pres_x.size()-1);
			double dt = t_max - t_min;
			if(dt > 2*acos(-1)) dt = 2*acos(-1);
			pi1path = dt* helix_r->at(ptid);
		}
		vector<double>pi2res_t;
		for(int ih=0;ih<pi2res_x.size();++ih){
			pi2res_t.push_back(hypot(pi2res_x.at(ih),pi2res_z.at(ih)));
			double t_min = helix_t->at(ptid).at(0);
			double t_max = helix_t->at(ptid).at(pres_x.size()-1);
			double dt = t_max - t_min;
			if(dt > 2*acos(-1)) dt = 2*acos(-1);
			pi2path = dt* helix_r->at(ptid);
		}
		res_pmom_t = MomTRes(pnh,pres_t,pmom,helix_r->at(ptid),ppath); 
		res_pi1mom_t = MomTRes(pi1nh,pi1res_t,pi1mom,helix_r->at(pi1tid),pi1path); 
		res_pi2mom_t = MomTRes(pi2nh,pi2res_t,pi2mom,helix_r->at(pi2tid),pi2path); 

		HistLdMomtResi->Fill((Ldmom_t-G4Ldmom_t)/Ldmom_t);
		HistLdThResi->Fill((LdTh-G4LdTh));
		HistLdPhResi->Fill((LdPh-G4LdPh));


		resi_pmom_t = (pmom_t - G4pmom_t)/ pmom_t;
		resi_pi1mom_t = (pi1mom_t - G4pi1mom_t)/ pi1mom_t;
		resi_pi2mom_t = (pi2mom_t - G4pi2mom_t)/ pi2mom_t;
		HistPMomtResi->Fill(resi_pmom_t);
		HistPi1MomtResi->Fill(resi_pi1mom_t);
		HistPi2MomtResi->Fill(resi_pi2mom_t);
		HistPMomtPull->Fill(resi_pmom_t/res_pmom_t);
		HistPi1MomtPull->Fill(resi_pi1mom_t/res_pi1mom_t);
		HistPi2MomtPull->Fill(resi_pi2mom_t/res_pi2mom_t);
//Resolutions and Residuals
		
		pPh = atan2(pmom_x,pmom_z);
		pTh = acos(pmom_y/pmom);
		G4pPh = atan2(G4pmom_x,G4pmom_z);
		G4pTh = acos(G4pmom_y/G4pmom);
		resi_pPh = pPh - G4pPh ;
		resi_pTh = pTh - G4pTh ;
		res_pPh = PhiRes(res_pmom_t,helix_r->at(ptid),ppath);
		res_pTh = 1.5 * ThetaRes(pnh,pres_y,ppath,pTh);
		HistPPhRes->Fill(res_pPh);
		HistPPhPull->Fill(resi_pPh/res_pPh);
		HistPThRes->Fill(res_pTh);
		HistPThPull->Fill(resi_pTh/res_pTh);
		HistPPhResi->Fill(resi_pPh);
		HistPThResi->Fill(resi_pTh);

		pi1Ph = atan2(pi1mom_x,pi1mom_z);
		pi1Th = acos(pi1mom_y/pi1mom);
		G4pi1Ph = atan2(G4pi1mom_x,G4pi1mom_z);
		G4pi1Th = acos(G4pi1mom_y/G4pi1mom);
		resi_pi1Ph = pi1Ph - G4pi1Ph ;
		resi_pi1Th = pi1Th - G4pi1Th ;
		res_pi1Ph = PhiRes(res_pi1mom_t,helix_r->at(pi1tid),pi1path);
		res_pi1Th =2* ThetaRes(pi1nh,pi1res_y,pi1path,pi1Th);
		HistPi1PhRes->Fill(res_pi1Ph);
		HistPi1PhPull->Fill(resi_pi1Ph/res_pi1Ph);
		HistPi1ThRes->Fill(res_pi1Th);
		HistPi1ThPull->Fill(resi_pi1Th/res_pi1Th);
		HistPi1PhResi->Fill(resi_pi1Ph);
		HistPi1ThResi->Fill(resi_pi1Th);


		pi2Ph = atan2(pi2mom_x,pi2mom_z);
		pi2Th = acos(pi2mom_y/pi2mom);
		G4pi2Ph = atan2(G4pi2mom_x,G4pi2mom_z);
		G4pi2Th = acos(G4pi2mom_y/G4pi2mom);
		resi_pi2Ph = pi2Ph - G4pi2Ph ;
		resi_pi2Th = pi2Th - G4pi2Th ;
		res_pi2Ph = PhiRes(res_pi2mom_t,helix_r->at(pi2tid),pi2path);
		res_pi2Th = 2*ThetaRes(pi2nh,pi2res_y,pi2path,pi2Th);
		HistPi2PhRes->Fill(res_pi2Ph);
		HistPi2PhPull->Fill(resi_pi2Ph/res_pi2Ph);
		HistPi2ThRes->Fill(res_pi2Th);
		HistPi2ThPull->Fill(resi_pi2Th/res_pi2Th);
		HistPi2PhResi->Fill(resi_pi2Ph);
		HistPi2ThResi->Fill(resi_pi2Th);
//		res_pTh = 3.431e-3;	
//		res_pi1Th = 4.897e-3;	
//		res_pi2Th = 4.161e-3;	
		
//Kinematic Fit
		LVp = SwapYZ(LVp);
		LVpi1 = SwapYZ(LVpi1);
		TLorentzVector LVLd = LVp+LVpi1;
		FourVectorFitter KFLd(LVp,LVpi1,LVLd);
		LVp = SwapYZ(LVp);
		LVpi1 = SwapYZ(LVpi1);
		LVLd = LVp+LVpi1;
		//		LVLd = TLorentzVector(Vp+Vpi1,hypot(mL,(Vp+VPi1).Mag()));
		KFLd.SetInvMass(mL);
		KFLd.SetMaximumStep(10);
		double resparp[3] = {pmom_t*res_pmom_t,res_pTh,res_pPh};
		double parp[3] = {pmom_t,pTh,pPh};
		double res_pmom = ResP(resparp,parp);
		double resparpi1[3] = {pi1mom_t*res_pi1mom_t,res_pi1Th,res_pi1Ph};
		double parpi1[3] = {pi1mom_t,pi1Th,pi1Ph};
		double res_pi1mom = ResP(resparpi1,parpi1);
		double VarianceLd[8] = {
			res_pmom*res_pmom,res_pTh*res_pTh,res_pPh*res_pPh,
			res_pi1mom*res_pi1mom,res_pi1Th*res_pi1Th,res_pi1Ph*res_pi1Ph,
			0,0};
		double DiagElemLd[36] = {0};
		for(int ic=0;ic<6;++ic){
		for(int ir=0;ir<6;++ir){
			if(ic==0 and ir == 2){
				DiagElemLd[ic*6+ir] = -res_pmom_t*pmom_t*res_pPh;
				DiagElemLd[ir*6+ic] = -res_pmom_t*pmom_t*res_pPh;
			}
			if(ic==0 and ir == 1){
				DiagElemLd[ic*6+ir] = pmom_t*cos(pTh)/sin(pTh)/sin(pTh) * res_pTh*res_pTh; 
				DiagElemLd[ir*6+ic] = pmom_t*cos(pTh)/sin(pTh)/sin(pTh) * res_pTh*res_pTh; 
			}
			if(ic==3 and ir == 5){
				DiagElemLd[ic*6+ir] = +res_pi1mom_t*pi1mom_t*res_pi1Ph;
				DiagElemLd[ir*6+ic] = +res_pi1mom_t*pi1mom_t*res_pi1Ph;
			}
			if(ic==3 and ir == 4){
				DiagElemLd[ic*6+ir] = pi1mom_t*cos(pi1Th)/sin(pi1Th)/sin(pi1Th) * res_pi1Th*res_pi1Th; 
				DiagElemLd[ir*6+ic] = pi1mom_t*cos(pi1Th)/sin(pi1Th)/sin(pi1Th) * res_pi1Th*res_pi1Th; 
			}
		}
		}
		TMatrixD DiagLd(6,6,DiagElemLd);
		KFLd.SetVariance(VarianceLd);
		KFLd.AddDiagonals(DiagLd);
		Chi2Ld=		KFLd.DoKinematicFit();
		CLLd = 1-ROOT::Math::chisquared_cdf(Chi2Ld,KFLd.GetNDF());
		ndfLd = KFLd.GetNDF();
		auto contLd = KFLd.GetFittedLV();
		auto PullLd = KFLd.GetPull();
		auto LVpKF = SwapYZ(contLd.at(0));
		auto LVpi1KF = SwapYZ(contLd.at(1));
		auto LVLdKF = SwapYZ(contLd.at(2));
		XiMassLdKF = (G4LVpi2+LVLdKF).Mag();
		double XiMassLd = (G4LVpi2+LVLd).Mag();
		auto VLdCor = LVLd.Vect();
		TLorentzVector LVLdCor = TLorentzVector(VLdCor,hypot(VLdCor.Mag(),mL));
		double XiMassLdCor = (G4LVpi2+LVLdCor).Mag();
		
		KFLdmom = LVLdKF.Vect().Mag();
		KFLdmom_x = LVLdKF.X();
		KFLdmom_y = LVLdKF.Y();
		KFLdmom_z = LVLdKF.Z();
		KFLdmom_t = hypot(KFLdmom_x,KFLdmom_z);
		KFLdPh = atan2(KFLdmom_x,KFLdmom_z);
		KFLdTh = acos(KFLdmom_y/KFLdmom);
	
		KFpmom = LVpKF.Vect().Mag();
		KFpmom_x = LVpKF.X();
		KFpmom_y = LVpKF.Y();
		KFpmom_z = LVpKF.Z();
		KFpmom_t = hypot(KFpmom_x,KFpmom_z);
		KFpPh = atan2(KFpmom_x,KFpmom_z);
		KFpTh = acos(KFpmom_y/KFpmom);
		
		KFpi1mom = LVpi1KF.Vect().Mag();
		KFpi1mom_x = LVpi1KF.X();
		KFpi1mom_y = LVpi1KF.Y();
		KFpi1mom_z = LVpi1KF.Z();
		KFpi1mom_t = hypot(KFpi1mom_x,KFpi1mom_z);
		KFpi1Ph = atan2(KFpi1mom_x,KFpi1mom_z);
		KFpi1Th = acos(KFpi1mom_y/KFpi1mom);
		
		HistLdMomtKFResi->Fill((KFLdmom_t-G4Ldmom_t)/KFLdmom_t);
		HistLdThKFResi->Fill(KFLdTh-G4LdTh);
		HistLdPhKFResi->Fill(KFLdPh-G4LdPh);

		HistPMomtKFResi->Fill((KFpmom_t-G4pmom_t)/KFpmom_t);
		HistPThKFResi->Fill(KFpTh-G4pTh);
		HistPPhKFResi->Fill(KFpPh-G4pPh);
	
		HistPi1MomtKFResi->Fill((KFpi1mom_t-G4pi1mom_t)/KFpi1mom_t);
		HistPi1ThKFResi->Fill(KFpi1Th-G4pi1Th);
		HistPi1PhKFResi->Fill(KFpi1Ph-G4pi1Ph);

		//		if(PullLd.size()==6){
		HistLdKFCL->Fill(CLLd); 
		HistLdKFChi2->Fill(Chi2Ld); 
		if(CLLd > Conf_cut){
			HistPMomKFPull->Fill(PullLd.at(0));
			HistPThKFPull->Fill(PullLd.at(1));
			HistPPhKFPull->Fill(PullLd.at(2));
			HistPi1MomKFPull->Fill(PullLd.at(3));
			HistPi1ThKFPull->Fill(PullLd.at(4));
			HistPi1PhKFPull->Fill(PullLd.at(5));
			HistXiMass->Fill(XiMassLd);
			HistXiMassKF->Fill(XiMassLdKF);
			HistXiMassCor->Fill(XiMassLdCor);
		}
		auto VLd = KFLd.GetUnmeasuredCovariance();
		res_Ldmom = sqrt(VLd(0,0));
		res_LdTh = sqrt(VLd(1,1));
		res_LdPh = sqrt(VLd(2,2));
		double VarianceXi[8] = {
			res_Ldmom*res_Ldmom,res_LdTh*res_LdTh,res_LdPh*res_LdPh,
			res_pi2mom_t*res_pi2mom_t*pi2mom_t*pi2mom_t,res_pi2Th*res_pi2Th,res_pi2Ph*res_pi2Ph,
			0,0};
		auto LVLdKFH = SwapYZ(LVLdKF);
		auto LVpi2H = SwapYZ(LVpi2);
		auto LVXiH = LVLdKFH+LVpi2H;
		FourVectorFitter KFXi(LVLdKFH,LVpi2H,LVXiH);
		KFXi.SetInvMass(mXi);
		KFXi.SetMaximumStep(10);
		KFXi.SetVariance(VarianceXi);
		Chi2Xi=		KFXi.DoKinematicFit();
		double CLXi = 1-ROOT::Math::chisquared_cdf(Chi2Xi,KFXi.GetNDF());
		ndfXi = KFXi.GetNDF();
		auto contXi = KFXi.GetFittedLV();
		auto PullXi = KFXi.GetPull();
		
//Kinematic Fit

//Polarization
		PolaAnal G4Pola(G4Vkm,G4Vkp,G4Vxi_decay,G4Vl_decay,G4Vp);
		PolaAnal Pola(G4Vkm,G4Vkp,Vxi,Vl,Vp);
		auto G4th = cos(G4Pola.GetTheta());
		auto G4pha = cos(G4Pola.GetPhi3());
		auto G4phb = cos(G4Pola.GetPhi1());
		auto G4phc = cos(G4Pola.GetPhi2());
		HistG4PolTh->Fill(G4th);
		HistG4PolPha->Fill(G4pha);
		HistG4PolPhb->Fill(G4phb);
		HistG4PolPhc->Fill(G4phc);
		auto th = cos(Pola.GetTheta());
		auto pha = cos(Pola.GetPhi3());
		auto phb = cos(Pola.GetPhi1());
		auto phc = cos(Pola.GetPhi2());
		HistPolTh->Fill(th);
		HistPolPha->Fill(pha);
		HistPolPhb->Fill(phb);
		HistPolPhc->Fill(phc);
//Polarization

		HistPMomtRes->Fill(res_pmom_t);
		HistPi1MomtRes->Fill(res_pi1mom_t);
		HistPi2MomtRes->Fill(res_pi2mom_t);

	}
	{
		HistPolTh->SetLineColor(kRed);
		HistPolPha->SetLineColor(kRed);
		HistPolPhb->SetLineColor(kRed);
		HistPolPhc->SetLineColor(kRed);
		TCanvas* c1 = new TCanvas("c1","c1",600,600);
		c1->Divide(2,2);
		c1->cd(1);
		HistG4PolTh->Draw();
		HistPolTh->Draw("same");
		HistG4PolTh->GetXaxis()->SetRangeUser(-1.1,1.1);
		c1->cd(2);
		HistG4PolPhb->Draw();
		HistPolPhb->Draw("same");
		HistG4PolPhb->GetXaxis()->SetRangeUser(-1.1,1.1);
		c1->cd(3);
		HistG4PolPhc->Draw();
		HistPolPhc->Draw("same");
		HistG4PolPhc->GetXaxis()->SetRangeUser(-1.1,1.1);
		c1->cd(4);
		HistG4PolPha->Draw();
		HistPolPha->Draw("same");
		HistG4PolPha->GetXaxis()->SetRangeUser(-1.1,1.1);
	}
	{
		TCanvas* c2 = new TCanvas("c2","c2",1200,600);
		c2->Divide(2,2);
		c2->cd(1);
		HistPMomtRes->Draw();
		c2->cd(2);
		HistPi1MomtRes->Draw();
		c2->cd(3);
		HistPi2MomtRes->Draw();
		TCanvas* c3 = new TCanvas("c3","c3",1200,600);
		c3->Divide(2,2);
		c3->cd(1);
		HistPMomtResi->Draw();
		c3->cd(2);
		HistPi1MomtResi->Draw();
		c3->cd(3);
		HistPi2MomtResi->Draw();
		TCanvas* c4 = new TCanvas("c4","c4",1200,600);
		c4->Divide(2,2);
		c4->cd(1);
		HistPMomtPull->Draw();
		HistPMomtPull->Fit("fGaus");
		c4->cd(2);
		HistPi1MomtPull->Draw();
		HistPi1MomtPull->Fit("fGaus");
		c4->cd(3);
		HistPi2MomtPull->Draw();
		HistPi2MomtPull->Fit("fGaus");
	}
	{
		TCanvas* c5 = new TCanvas("c5","c5",1200,600);
		c5->Divide(3,2);
		c5->cd(1);
		HistPPhResi->Draw();
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c5->cd(2);
		HistPi1PhResi->Draw();
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c5->cd(3);
		HistPi2PhResi->Draw();
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c5->cd(4);
		HistPThResi->Draw();
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c5->cd(5);
		HistPi1ThResi->Draw();
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c5->cd(6);
		HistPi2ThResi->Draw();
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		TCanvas* c6 = new TCanvas("c6","c6",1200,600);
		c6->Divide(3,2);
		c6->cd(1);
		HistPPhRes->Draw();
		c6->cd(2);
		HistPi1PhRes->Draw();
		c6->cd(3);
		HistPi2PhRes->Draw();
		c6->cd(4);
		HistPThRes->Draw();
		c6->cd(5);
		HistPi1ThRes->Draw();
		c6->cd(6);
		HistPi2ThRes->Draw();
		TCanvas* c7 = new TCanvas("c7","c7",1200,600);
		c7->Divide(3,2);
		c7->cd(1);
		HistPPhPull->Draw();
		HistPPhPull->Fit("fGaus","Q");
		cout<<"PPh Pull = "<<fGaus->GetParameter(2)<<endl;
		c7->cd(2);
		HistPi1PhPull->Draw();
		HistPi1PhPull->Fit("fGaus","Q");
		cout<<"Pi1Ph Pull = "<<fGaus->GetParameter(2)<<endl;
		c7->cd(3);
		HistPi2PhPull->Draw();
		HistPi2PhPull->Fit("fGaus","Q");
		cout<<"Pi2Ph Pull = "<<fGaus->GetParameter(2)<<endl;
		c7->cd(4);
		HistPThPull->Draw();
		HistPThPull->Fit("fGaus","Q");
		cout<<"PTh Pull = "<<fGaus->GetParameter(2)<<endl;
		c7->cd(5);
		HistPi1ThPull->Draw();
		HistPi1ThPull->Fit("fGaus","Q");
		cout<<"Pi1Th Pull = "<<fGaus->GetParameter(2)<<endl;
		c7->cd(6);
		HistPi2ThPull->Draw();
		HistPi2ThPull->Fit("fGaus","Q");
		cout<<"Pi2Th Pull = "<<fGaus->GetParameter(2)<<endl;
	}
	{
		fGaus->SetRange(-2,2);
		TCanvas* c8 = new TCanvas("c8","c8",1200,600);
		c8->Divide(3,2);
		c8->cd(1);
		HistPMomKFPull->Draw();
		HistPMomKFPull->Fit("fGaus","QR");
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c8->cd(2);
		HistPThKFPull->Draw();
		HistPThKFPull->Fit("fGaus","QR");
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c8->cd(3);
		HistPPhKFPull->Draw();
		HistPPhKFPull->Fit("fGaus","QR");
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c8->cd(4);
		HistPi1MomKFPull->Draw();
		HistPi1MomKFPull->Fit("fGaus","QR");
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c8->cd(5);
		HistPi1ThKFPull->Draw();
		HistPi1ThKFPull->Fit("fGaus","QR");
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		c8->cd(6);
		HistPi1PhKFPull->Draw();
		HistPi1PhKFPull->Fit("fGaus","QR");
		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
		TCanvas* c9 = new TCanvas("c9","c9",1200,600);
		c9->Divide(3,1);
		c9->cd(1);
		HistLdKFChi2->Draw();
		double Chi2_cut = TMath::ChisquareQuantile(1-Conf_cut,ndfLd);
		double tail = HistLdKFChi2->GetMaximum()* 0.4;
		TArrow* Chi2Arrow = new TArrow(Chi2_cut,tail,Chi2_cut,0);
		Chi2Arrow->SetArrowSize(0.02);
		Chi2Arrow->Draw();	
		c9->cd(2);
		HistLdKFCL->Draw();
		tail = HistLdKFCL->GetMaximum()* 0.4;
		TArrow* PvalArrow = new TArrow(Conf_cut,tail,Conf_cut,0);
		PvalArrow->SetArrowSize(0.02);
		PvalArrow->Draw();	
		c9->cd(3);
		HistXiMassKF->Draw();
		HistXiMassKF->GetXaxis()->SetTitle("M(#pi#Lambda)");
		HistXiMassKF->SetLineColor(kRed);
		HistXiMassCor->SetLineColor(kBlack);
		HistXiMass->Draw("same");
		HistXiMassCor->Draw("same");
		TCanvas* c10 = new TCanvas("c10","c10",1200,600);
		c10->Divide(3,3);
		c10->cd(1);
		HistLdMomtKFResi->Draw();
		HistLdMomtKFResi->SetLineColor(kRed);
		HistLdMomtKFResi->GetXaxis()->SetTitle("#delta P/P");
		HistLdMomtResi->Draw("same");
		c10->cd(2);
		HistLdThKFResi->Draw();
		HistLdThKFResi->SetLineColor(kRed);
		HistLdThKFResi->GetXaxis()->SetTitle("#delta #theta");
		HistLdThResi->Draw("same");
		c10->cd(3);
		HistLdPhKFResi->Draw();
		HistLdPhKFResi->SetLineColor(kRed);
		HistLdPhKFResi->GetXaxis()->SetTitle("#delta #theta");
		HistLdPhResi->Draw("same");
		c10->cd(4);
		HistPMomtKFResi->Draw();
		HistPMomtKFResi->SetLineColor(kRed);
		HistPMomtKFResi->GetXaxis()->SetTitle("#delta P/P");
		HistPMomtResi->Draw("same");
		c10->cd(5);
		HistPThKFResi->Draw();
		HistPThKFResi->SetLineColor(kRed);
		HistPThKFResi->GetXaxis()->SetTitle("#delta #theta");
		HistPThResi->Draw("same");
		c10->cd(6);
		HistPPhKFResi->Draw();
		HistPPhKFResi->SetLineColor(kRed);
		HistPPhKFResi->GetXaxis()->SetTitle("#delta #phi");
		HistPPhResi->Draw("same");
		c10->cd(7);
		HistPi1MomtKFResi->Draw();
		HistPi1MomtKFResi->SetLineColor(kRed);
		HistPi1MomtKFResi->GetXaxis()->SetTitle("#delta P/P");
		HistPi1MomtResi->Draw("same");
		c10->cd(8);
		HistPi1ThKFResi->Draw();
		HistPi1ThKFResi->SetLineColor(kRed);
		HistPi1ThKFResi->GetXaxis()->SetTitle("#delta #theta");
		HistPi1ThResi->Draw("same");
		c10->cd(9);
		HistPi1PhKFResi->Draw();
		HistPi1PhKFResi->SetLineColor(kRed);
		HistPi1PhKFResi->GetXaxis()->SetTitle("#delta #phi");
		HistPi1PhResi->Draw("same");
//		HistXiMass->Fit("fGaus");
//		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
//		HistXiMassKF->Fit("fGaus");
//		cout<<"sig = "<<fGaus->GetParameter(2)<<endl;
	}
}

