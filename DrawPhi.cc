#include "/Users/MIN/ROOTSharedLibs/MyStyle.hh"
#include "Dir.hh" 
int ntTpc,nhHtof,nhittpc;
double yHtof[500];
int didHtof[500];
double xtpc[500];
double ytpc[500];
double ztpc[500];
double InvMPhi1,InvMPhi2;
double PKm1,PKm2,PKp1,PKp2;
double cd1,cd2;
double PPhi1,PPhi1_x,PPhi1_y,PPhi1_z;
double PPhi2,PPhi2_x,PPhi2_y,PPhi2_z;
bool FlagPhi1,FlagPhi2;
bool GoodPhi1,GoodPhi2;
int tidKm1,tidKp1,tidKm2,tidKp2;
double dM;
double MM;
bool GoodCombi;
TFile* file;
TTree* tree;
int ent;
double mom = 1.2;
double cd_cut = 5;
vector<double>* nhtrack;
vector<double>* helix_cx;
vector<double>* helix_cy;
vector<double>* helix_dz;
vector<double>* helix_r;
vector<double>* helix_z0;
vector<double>* mom0;
vector<double>* charge;
vector<vector<double>>* helix_t;
vector<vector<double>>* hitpos_x;
vector<vector<double>>* hitpos_y;
vector<vector<double>>* hitpos_z;
double TwoPi = 2*acos(-1);
double ToDeg = 180 / acos(-1);
double GetAngle(double t){
	double h_x = cos(t);
	double h_y = sin(t);
	double x = h_y;
	double y = -h_x;
	double ang = atan2(y,x);
	return ang * ToDeg; 
}
void DrawPhi(){
		
//	TString filename = Form("PPBar4PiAnal_%gGeV_cd%g.root",mom,cd_cut);
	TString filename = Form("PPBarAnal_%gGeV_cd%g.root",mom,cd_cut);
//	TString filename = Form("DPBarFermiAnal_%gGeV_cd%g.root",mom,cd_cut);
	file = new TFile(filename);
	tree = (TTree*)file->Get("tree");
	ent = tree->GetEntries();
	tree->SetBranchAddress("nhHtof",&nhHtof);
	tree->SetBranchAddress("yHtof",yHtof);
	tree->SetBranchAddress("didHtof",didHtof);
	tree->SetBranchAddress("ntTpc",&ntTpc);
	tree->SetBranchAddress("nhittpc",&nhittpc);
	tree->SetBranchAddress("xtpc",xtpc);
	tree->SetBranchAddress("ytpc",ytpc);
	tree->SetBranchAddress("ztpc",ztpc);
	tree->SetBranchAddress("GoodCombi",&GoodCombi);
	tree->SetBranchAddress("hitpos_x",&hitpos_x);
	tree->SetBranchAddress("hitpos_y",&hitpos_y);
	tree->SetBranchAddress("hitpos_z",&hitpos_z);
	tree->SetBranchAddress("dM",&dM);
	tree->SetBranchAddress("MM",&MM);

	tree->SetBranchAddress("FlagPhi1",&FlagPhi1);
	tree->SetBranchAddress("GoodPhi1",&GoodPhi1);
	tree->SetBranchAddress("InvMPhi1",&InvMPhi1);
	tree->SetBranchAddress("cd1",&cd1);
	tree->SetBranchAddress("PPhi1",&PPhi1);
	tree->SetBranchAddress("PPhi1_x",&PPhi1_x);
	tree->SetBranchAddress("PPhi1_y",&PPhi1_y);
	tree->SetBranchAddress("PPhi1_z",&PPhi1_z);
	tree->SetBranchAddress("tidKm1",&tidKm1);
	tree->SetBranchAddress("PKm1",&PKm1);
	tree->SetBranchAddress("tidKp1",&tidKp1);
	tree->SetBranchAddress("PKp1",&PKp1);
	
	tree->SetBranchAddress("FlagPhi2",&FlagPhi2);
	tree->SetBranchAddress("GoodPhi2",&GoodPhi2);
	tree->SetBranchAddress("InvMPhi2",&InvMPhi2);
	tree->SetBranchAddress("cd2",&cd2);
	tree->SetBranchAddress("PPhi2",&PPhi2);
	tree->SetBranchAddress("PPhi2_x",&PPhi2_x);
	tree->SetBranchAddress("PPhi2_y",&PPhi2_y);
	tree->SetBranchAddress("PPhi2_z",&PPhi2_z);
	tree->SetBranchAddress("tidKm2",&tidKm2);
	tree->SetBranchAddress("PKm2",&PKm2);
	tree->SetBranchAddress("tidKp2",&tidKp2);
	tree->SetBranchAddress("PKp2",&PKp2);
	tree->SetBranchAddress("ntTpc",&ntTpc);
	tree->SetBranchAddress("nhtrack",&nhtrack);
	tree->SetBranchAddress("helix_cx",&helix_cx);
	tree->SetBranchAddress("helix_cy",&helix_cy);
	tree->SetBranchAddress("helix_dz",&helix_dz);
	tree->SetBranchAddress("helix_r",&helix_r);
	tree->SetBranchAddress("helix_z0",&helix_z0);
	tree->SetBranchAddress("mom0",&mom0);
	tree->SetBranchAddress("charge",&charge);
	tree->SetBranchAddress("helix_t",&helix_t);
	SetStyle();
}
void EventDisplay(int iev = 0){
	TCanvas* c1 = new TCanvas("c","c",800,800);
	TH2Poly* H = tpc::InitializeHistogram();
	H->Draw("colz");
	H->Reset("");
	tree->GetEntry(iev);
	while(!FlagPhi2 or nhHtof < 3){
//	while(!FlagPhi2 or nhHtof < 3 or GoodPhi1 or GoodPhi2){}
		iev++;
		tree->GetEntry(iev);
		cout<<"No 2Phi or trg, Going to ev "<<iev<<endl;
	}
	double Km1Par[3] = {helix_cx->at(tidKm1),helix_cy->at(tidKm1),helix_r->at(tidKm1)};
	double Kp1Par[3] = {helix_cx->at(tidKp1),helix_cy->at(tidKp1),helix_r->at(tidKp1)};
	double Km2Par[3] = {helix_cx->at(tidKm2),helix_cy->at(tidKm2),helix_r->at(tidKm2)};
	double Kp2Par[3] = {helix_cx->at(tidKp2),helix_cy->at(tidKp2),helix_r->at(tidKp2)};
	int nhKm1 = nhtrack->at(tidKm1);	
	int nhKp1 = nhtrack->at(tidKp1);	
	int nhKm2 = nhtrack->at(tidKm2);	
	int nhKp2 = nhtrack->at(tidKp2);	
	double T0Km1	= GetAngle(helix_t->at(tidKm1).at(0));
	double T1Km1	= GetAngle(helix_t->at(tidKm1).at(nhKm1-1));
	double T0Kp1	= GetAngle(helix_t->at(tidKp1).at(0));
	double T1Kp1	= GetAngle(helix_t->at(tidKp1).at(nhKp1-1));
	double T0Km2	= GetAngle(helix_t->at(tidKm2).at(0));
	double T1Km2	= GetAngle(helix_t->at(tidKm2).at(nhKm2-1));
	double T0Kp2	= GetAngle(helix_t->at(tidKp2).at(0));
	double T1Kp2	= GetAngle(helix_t->at(tidKp2).at(nhKp2-1));
	bool good = false;
	bool wrong = false;
	for(int ih=0;ih<nhittpc;++ih){
		cout<<ztpc[ih]<< " , "<<xtpc[ih]<<endl;
		H->Fill(ztpc[ih],xtpc[ih]);
	}
	if(GoodPhi1 and GoodPhi2){
		cout<<"Good"<<endl;
		good = true;
	}
	if(!GoodPhi1 and !GoodPhi2){
		cout<<"Wrong"<<endl;
		wrong = true;
	}

	cout<<T0Km1<<" , "<<T1Km1<<endl;
	TEllipse* Km1;
	TEllipse* Kp1;
	TEllipse* Km2;
	TEllipse* Kp2;
	if(Km1)	delete Km1;
	if(Kp1)	delete Kp1;
	if(Km2)	delete Km2;
	if(Kp2)	delete Kp2;
	double path = 20;

	Km1 = new TEllipse(Km1Par[1] - 143,-Km1Par[0],Km1Par[2],Km1Par[2],T0Km1+path/Km1Par[2] * 180./acos(-1),T1Km1);
	Kp1 = new TEllipse(Kp1Par[1] - 143,-Kp1Par[0],Kp1Par[2],Kp1Par[2],T0Kp1-path/Kp1Par[2] * 180./acos(-1),T1Kp1);
	Km1->Draw("");
	Kp1->Draw("");
	Km1->SetNoEdges();
  Km1->SetFillStyle(0);
  Km1->SetLineWidth(2);
	Kp1->SetNoEdges();
  Kp1->SetFillStyle(0);
  Kp1->SetLineWidth(2);
	
	Km2 = new TEllipse(Km2Par[1] - 143,-Km2Par[0],Km2Par[2],Km2Par[2],T0Km2+path/Km2Par[2] * 180./acos(-1),T1Km2);
	Kp2 = new TEllipse(Kp2Par[1] - 143,-Kp2Par[0],Kp2Par[2],Kp2Par[2],T0Kp2-path/Kp2Par[2] * 180./acos(-1),T1Kp2);
	Km2->Draw("");
	Kp2->Draw("");
	Km2->SetNoEdges();
  Km2->SetFillStyle(0);
  Km2->SetLineWidth(2);
	Kp2->SetNoEdges();
  Kp2->SetFillStyle(0);
  Kp2->SetLineWidth(2);
	Km2->SetLineColor(kGreen);
	Kp2->SetLineColor(kGreen);
	if(good){
		c1->SaveAs(Form("2Phi_ev%d_GoodPairing.png",iev));
	}
	if(wrong){
		c1->SaveAs(Form("2Phi_ev%d_WrongPairing.png",iev));
	}
}



void DrawInvMass(){
	TFile* fileH = new TFile(Form("HistIM_%gGeV.root",mom),"recreate");
	double lowLim = 0.98;
	double highLim = 1.06;
	if(mom==1.2) highLim = 1.16;
	TH1D* InvMPhi= new TH1D("IMPhi","IMPhi",1000,lowLim,highLim);
	TH1D* InvMPhiAllGood= new TH1D("IMPhiGood","IMPhiGood",1000,lowLim,highLim);
	TH1D* InvMPhiWrong= new TH1D("IMPhiWrong","IMPhiWrong",1000,lowLim,highLim);
	TH1D* InvMPhi2PiPhi= new TH1D("IMPhi2PiPhi","IMPhi2PiPhi",1000,lowLim,highLim);
	TH1D* InvMPhi4Pi= new TH1D("IMPhi4Pi","IMPhi4Pi",1000,lowLim,highLim);
	TH2D* InvMPhi2D= new TH2D("IMPhi2D","IMPhi2D",100,lowLim,highLim,100,lowLim,highLim);
	TH2D* InvMPhi2DAllGood = new TH2D("IMPhi2DGood","IMPhi2DGood",100,lowLim,highLim,100,lowLim,highLim);
	TH2D* InvMPhi2DWrong = new TH2D("IMPhi2DWrong","IMPhi2DWrong",100,lowLim,highLim,100,lowLim,highLim);
	TH2D* InvMPhi2D2PiPhi = new TH2D("IMPhi2D2PiPhi","IMPhi2D2PiPhi",100,lowLim,2*highLim,100,lowLim,2*highLim);
	TH2D* InvMPhi2D4Pi = new TH2D("IMPhi2D4Pi","IMPhi2D4Pi",100,lowLim,2*highLim,100,lowLim,2*highLim);
	for(int i=0;i<ent;++i){
		tree->GetEntry(i);
		if(!FlagPhi2) continue;
		if(nhHtof<3) continue;
		InvMPhi->Fill(InvMPhi1);
		InvMPhi->Fill(InvMPhi2);
		InvMPhi2D->Fill(InvMPhi1,InvMPhi2);
		if(i < 1e5){
			if(GoodPhi1 and GoodPhi2){
				InvMPhiAllGood->Fill(InvMPhi1);
				InvMPhiAllGood->Fill(InvMPhi2);
				InvMPhi2DAllGood->Fill(InvMPhi1,InvMPhi2);
			}
			if(!GoodPhi1 and !GoodPhi2){
				InvMPhiWrong->Fill(InvMPhi1);
				InvMPhiWrong->Fill(InvMPhi2);
				InvMPhi2DWrong->Fill(InvMPhi1,InvMPhi2);
			}
		}
		else if(i<2e5){
			InvMPhi2PiPhi->Fill(InvMPhi1);
			InvMPhi2PiPhi->Fill(InvMPhi2);
			InvMPhi2D2PiPhi->Fill(InvMPhi1,InvMPhi2);
		}
		else if(i<3e5){
			InvMPhi4Pi->Fill(InvMPhi1);
			InvMPhi4Pi->Fill(InvMPhi2);
			InvMPhi2D4Pi->Fill(InvMPhi1,InvMPhi2);
		}
	}
	TCanvas*c1 = new TCanvas("HistIM","HistIM",700,700);
	InvMPhi->Draw();
	InvMPhi->GetYaxis()->SetNdivisions(5);
	InvMPhi->GetXaxis()->SetLabelSize(0.05);
	InvMPhi->GetYaxis()->SetLabelSize(0.05);
	InvMPhiAllGood->SetLineColor(kRed);
	InvMPhiAllGood->Draw("same");
	InvMPhiAllGood->GetYaxis()->SetNdivisions(5);
	InvMPhiAllGood->GetXaxis()->SetLabelSize(0.05);
	InvMPhiAllGood->GetYaxis()->SetLabelSize(0.05);
	InvMPhiWrong->SetLineColor(kCyan);
	InvMPhiWrong->GetYaxis()->SetNdivisions(5);
	InvMPhiWrong->GetXaxis()->SetLabelSize(0.05);
	InvMPhiWrong->GetYaxis()->SetLabelSize(0.05);
//	InvMPhiWrong->SetLineColor(kBlack);
	InvMPhiWrong->Draw("same");
	InvMPhi2PiPhi->SetLineColor(kGreen);
	InvMPhi2PiPhi->GetYaxis()->SetNdivisions(5);
	InvMPhi2PiPhi->GetXaxis()->SetLabelSize(0.05);
	InvMPhi2PiPhi->GetYaxis()->SetLabelSize(0.05);
	InvMPhi2PiPhi->Draw("same");
	InvMPhi4Pi->SetLineColor(kBlack);
	InvMPhi4Pi->GetYaxis()->SetNdivisions(5);
	InvMPhi4Pi->GetXaxis()->SetLabelSize(0.05);
	InvMPhi4Pi->GetYaxis()->SetLabelSize(0.05);
	InvMPhi4Pi->Draw("same");
	c1->Write();
	InvMPhiAllGood->Write();
	InvMPhiWrong->Write();
	InvMPhi->Write();
	InvMPhi2PiPhi->Write();
	InvMPhi4Pi->Write();
	TCanvas*c2 = new TCanvas("c2","c2",1500,500);
	c2->Divide(3,2);
	c2->cd(1);
	InvMPhi2D->Draw("colz");
	c2->cd(2);
	InvMPhi2DAllGood->Draw("colz");
	c2->cd(3);
	InvMPhi2DWrong->Draw("colz");
	c2->cd(4);
	InvMPhi2D2PiPhi->Draw("colz");
	c2->cd(5);
	InvMPhi2D4Pi->Draw("colz");
	InvMPhi2DAllGood->GetXaxis()->SetNdivisions(5);
	InvMPhi2DAllGood->GetXaxis()->SetLabelSize(0.05);
	InvMPhi2DAllGood->GetYaxis()->SetLabelSize(0.05);
	InvMPhi2DAllGood->Write();
	InvMPhi2DWrong->GetXaxis()->SetNdivisions(5);
	InvMPhi2DWrong->GetXaxis()->SetLabelSize(0.05);
	InvMPhi2DWrong->GetYaxis()->SetLabelSize(0.05);
	InvMPhi2DWrong->Write();
	InvMPhi2D2PiPhi->GetXaxis()->SetNdivisions(5);
	InvMPhi2D2PiPhi->GetXaxis()->SetLabelSize(0.05);
	InvMPhi2D2PiPhi->GetYaxis()->SetLabelSize(0.05);
	InvMPhi2D2PiPhi->Write();
	InvMPhi2D4Pi->GetXaxis()->SetNdivisions(5);
	InvMPhi2D4Pi->GetXaxis()->SetLabelSize(0.05);
	InvMPhi2D4Pi->GetYaxis()->SetLabelSize(0.05);
	InvMPhi2D4Pi->Write();
	cout<<"Acpt = "<<InvMPhiAllGood->GetEffectiveEntries()/2<<endl;
	cout<<"Rec = "<<InvMPhi->GetEffectiveEntries()/2<<endl;
	fileH->Write();
}
void DrawCM(){
	TFile* fileH = new TFile(Form("HistMom_%gGeV.root",mom),"recreate");
	TH1D* CMAll = new TH1D("EnergyAll","EnergyAll",1000,-3,1.);
	TH1D* CM2Phi = new TH1D("Energy2Phi","Energy2Phi",1000,-3,1);
	TH1D* CM2PiPhi = new TH1D("Energy2PiPHi","Energy2PiPhi",1000,-3,1.);
	TH1D* CM4Pi = new TH1D("Energy4Pi","Energy4Pi",1000,-3,1.);
	TH2D* HToF2Phi = new TH2D("HToF2Phi","HToF2Phi",36,0,36,100,-600,600);
	TH2D* HToF2PiPhi = new TH2D("HToF2PiPhi","HToF2PiPhi",36,0,36,100,-600,600);
	TH2D* HToF4Pi = new TH2D("HToF4Pi","HToF4Pi",36,0,36,100,-600,600);
	for(int i=0;i<ent;++i){
		tree->GetEntry(i);
		if(!FlagPhi2) continue;
		if(nhHtof<3) continue;
		CMAll->Fill(MM);		
		if(GoodPhi1 and GoodPhi2){
		}
		if(!GoodPhi1 and !GoodPhi2){
		}
		if(i < 1e5){
			CM2Phi->Fill(MM);	
			for(int ih=0;ih<nhHtof;++ih){
				HToF2Phi->Fill(didHtof[ih],yHtof[ih]);
			}
		}
		else if(i < 2e5){
			CM2PiPhi->Fill(MM);	
			for(int ih=0;ih<nhHtof;++ih){
				HToF2PiPhi->Fill(didHtof[ih],yHtof[ih]);
			}
		}
		else if(i < 3e5){
			CM4Pi->Fill(MM);	
			for(int ih=0;ih<nhHtof;++ih){
				HToF4Pi->Fill(didHtof[ih],yHtof[ih]);
			}
		}
	}	
	CM2Phi ->SetLineColor(kRed);
	CM2PiPhi ->SetLineColor(kGreen);
	CM4Pi ->SetLineColor(kBlack);
	CMAll->GetXaxis()->SetLabelSize(0.05);
	CMAll->GetYaxis()->SetNdivisions(5);
	CMAll->GetYaxis()->SetLabelSize(0.05);
	CM2Phi->GetXaxis()->SetLabelSize(0.05);
	CM2Phi->GetYaxis()->SetNdivisions(5);
	CM2Phi->GetYaxis()->SetLabelSize(0.05);
	CM2PiPhi->GetXaxis()->SetLabelSize(0.05);
	CM2PiPhi->GetYaxis()->SetNdivisions(5);
	CM2PiPhi->GetYaxis()->SetLabelSize(0.05);
	CM4Pi->GetXaxis()->SetLabelSize(0.05);
	CM4Pi->GetYaxis()->SetNdivisions(5);
	CM4Pi->GetYaxis()->SetLabelSize(0.05);
	TCanvas* c1 = new TCanvas("HistEnergy","HistEnergy",800,800);
	CMAll->Draw();
	CM2Phi->Draw("same");
	CM2PiPhi->Draw("same");
	CM4Pi->Draw("same");
	c1->Write();
	cout<<CMAll->GetEntries()<<endl;
	cout<<CM2Phi->GetEntries()<<endl;
	cout<<CM4Pi->GetEntries()<<endl;
	CMAll->Write();
	CM2Phi->Write();
	CM2PiPhi->Write();
	CM4Pi->Write();
	TCanvas* c2 = new TCanvas("c1","c1",800,800);
	HToF2Phi->Draw("colz");
	HToF2PiPhi->Draw("colz");
	HToF4Pi->Draw("colz");
	HToF2Phi->GetXaxis()->SetLabelSize(0.05);
	HToF2Phi->GetYaxis()->SetNdivisions(5);
	HToF2Phi->GetYaxis()->SetLabelSize(0.05);
	HToF2PiPhi->GetXaxis()->SetLabelSize(0.05);
	HToF2PiPhi->GetYaxis()->SetNdivisions(5);
	HToF2PiPhi->GetYaxis()->SetLabelSize(0.05);
	HToF4Pi->GetXaxis()->SetLabelSize(0.05);
	HToF4Pi->GetYaxis()->SetNdivisions(5);
	HToF4Pi->GetYaxis()->SetLabelSize(0.05);
	HToF2Phi->Write();
	HToF2PiPhi->Write();
	HToF4Pi->Write();
	fileH->Write();
	//	CM2PiPhi->Draw("same");
	/*
	CM2Phi->Draw("same");
	CM2PiPhi->Draw("same");
	CM4Pi->Draw("same");
*/
}
