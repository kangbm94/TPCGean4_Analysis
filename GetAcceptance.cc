#include "/Users/MIN/ROOTSharedLibs/MyStyle.hh"
void GetAcceptance(){
	SetStyle();
	TFile* file = new TFile("KpUniformHist.root");
//	TFile* file = new TFile("KpUniformHistNoReaction.root");
	TH2D* HGen = (TH2D*)file->Get("BeamGen");
	TH2D* HAcpt = (TH2D*)file->Get("BeamAcpt");
	TFile* file2 = new TFile("KpAcceptance.root","recreate");
	TTree* tree = new TTree("tree","tree");
	int nbx = HGen->GetNbinsX();
	int nby = HGen->GetNbinsY();
	double bwTheta = HGen->GetXaxis()->GetBinWidth(1);
	double Theta0 = HGen->GetXaxis()->GetXmin();
	double Theta1 = HGen->GetXaxis()->GetXmax();
	double bwP = HGen->GetYaxis()->GetBinWidth(1);
	double P0 = HGen->GetYaxis()->GetXmin();
	double P1 = HGen->GetYaxis()->GetXmax();
	double theta,P,gen,acpt,eff;
	cout<<Form("Theta (%g,%g) with %g bin",Theta0,Theta1,bwTheta)<<endl;
	cout<<Form("Mom (%g,%g) with %g bin",P0,P1,bwP)<<endl;
	TH2D* HEff = new TH2D("BeamAcceptance","BeamAcceptance",nbx,Theta0,Theta1,nby,P0,P1);
	tree->Branch("theta",&theta);
	tree->Branch("P",&P);
	tree->Branch("gen",&gen);
	tree->Branch("acpt",&acpt);
	tree->Branch("eff",&eff);
	for(double ith = 1; ith <= nbx; ++ith){
		theta = (ith - 0.5)*bwTheta +Theta0;
		for(double iP = 1; iP <= nby; ++iP){
			P = (iP - 0.5)*bwP +P0;
			gen = HGen->GetBinContent(ith,iP);
			acpt = HAcpt->GetBinContent(ith,iP);
			eff = acpt / gen;
			if(theta<1 and P < 1.2 and P > 1)	cout<<Form("(th,P, gen,acpt, eff) = ( %g,%g,%g,%g,%g)",theta,P,gen,acpt,eff)<<endl;
			HEff->SetBinContent(ith,iP,eff);
			tree->Fill();
		}
	}
	HGen->Write();
	HAcpt->Write();
	HEff->Write();
	file2->Write();
	TCanvas* c1 = new TCanvas("c1","c1",1200,600);
	c1->Divide(2,1);
	c1->cd(1);
	HGen->Draw("colz");
	c1->cd(2);
	HAcpt->Draw("colz");
	TCanvas* c2 = new TCanvas("c2","c2",600,600);
	HEff->Draw("colz");
	HEff->GetXaxis()->SetTitle("K^{+} Angle[deg]");
	HEff->GetYaxis()->SetTitle("K^{+} Momemtum[GeV/c]");
	c2->SaveAs("Acceptance.png");
}
