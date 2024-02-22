#include "Dir.hh" 
double md = 1.875612942;
int ntTpc,nhHtof,nhittpc;
int ititpc[500];
double xtpc[500];
double ytpc[500];
double ztpc[500];

int NumberOfTracks;
int PIDOfTrack[1000];
int ParentIDOfTrack[1000];
double MomentumOfTrack[1000];

double yHtof[500];
int didHtof[500];
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

int nPhi = 0;
int G4tidKm1,G4tidKp1,G4tidKm2,G4tidKp2;
bool GoodCombi;
bool GoodPhi1;
bool GoodPhi2;

double InvMPhi1,InvMPhi2,InvMPhiFake;
double InvMPhi1_Flip,InvMPhi2_Flip;
double PKm1,PKm2,PKp1,PKp2;
double Km1Len,Kp1Len,Km2Len,Kp2Len;
int G4nhKm1,G4nhKp1,G4nhKm2,G4nhKp2;
double G4PPhi1,G4PPhi2,G4PKm1,G4PKm2,G4PKp1,G4PKp2;
double cd1,cd2;
double PPhi1,PPhi1_x,PPhi1_y,PPhi1_z;
double PPhi2,PPhi2_x,PPhi2_y,PPhi2_z;
bool FlagPhi1,FlagPhi2;
int tidKm1,tidKp1,tidKm2,tidKp2;
double dM,MM;
TFile* file;
TTree* tree;
void Initialize(){
	G4tidKm1=-1;
	G4tidKp1=-1;
	G4tidKm2=-1;
	G4tidKp2=-1;
	nPhi = 0;
	dM= 9999;
	MM= 9999;
	GoodCombi = false;
	FlagPhi1=false;
	GoodPhi1=false;
	InvMPhi1=0;
	PKm1=0;
	PKp1=0;
	cd1 = -9999;
	PPhi1 = 0;
	PPhi1_x = 0;
	PPhi1_y = 0;
	PPhi1_z = 0;
	tidKm1=-1;
	tidKp1=-1;
	
	FlagPhi2=false;
	GoodPhi2=false;
	InvMPhi2=0;
	PKm2=0;
	PKp2=0;
	cd2 = -9999;
	PPhi2 = 0;
	PPhi2_x = 0;
	PPhi2_y = 0;
	PPhi2_z = 0;
	tidKm2=-1;
	tidKp2=-1;

}
double Dist(vector<TVector3> hit ){
	int ent = hit.size();
	double comp = -9999;
	for(int ih=0;ih<ent;++ih){
		auto hit1 = hit.at(ih);
		for(int ih2=ih;ih2<ent;++ih2){
			auto hit2 = hit.at(ih2);
			double dist = (hit1-hit2).Mag();
			if(comp < dist){
				comp = dist;
			}
		}
	}
	return comp;
}


int TPCToG4TrackID(vector<TVector3>TPCHit, int nhG4,int* tidG4, double* xG4,double* yG4,double* zG4 ,int& nhits){
	vector<TVector3> G4Hits;
	for(int ih=0;ih<nhG4;++ih){
		TVector3 G4Hit(xG4[ih],yG4[ih],zG4[ih]);
		G4Hits.push_back(G4Hit);
	}
	int MaxTracks = 1000;
	TH1I Counter("counter","counter",MaxTracks,0,MaxTracks);
	for(auto hit:TPCHit){
		double dl = 5000;
		int G4ID = -1;
		for(int ih=0;ih<nhG4;++ih){
			auto G4Hit = G4Hits.at(ih);
			double dist = (G4Hit - hit).Mag();
			if(dist < dl){
				dl = dist;
				G4ID = tidG4[ih];
			}
		}
		Counter.Fill(G4ID);
	}
	nhits = Counter.GetMaximum();
	int G4id = Counter.GetMaximumBin()-1;
	return G4id;
}
double mom=1.,cd_cut=10;
int conf = 0;//0->2Phi;1->2PiPhi;2->4Pi;3->DPBarFermi;
TString filename;
TString filename2;

void G4PhiDisplay(){
}


void G4PhiAnal(int dum){
	int ent = tree->GetEntries();
	double scale = 10.;
	ent = ent/scale;

	TFile* file2 = new TFile(filename2,"recreate");
	TTree* tree2 = new TTree("tree","tree");
	tree2->Branch("nhHtof",&nhHtof);
	tree2->Branch("yHtof",yHtof,"yHtof[500]/D");
	tree2->Branch("didHtof",didHtof,"didHtof[500]/I");

	tree2->Branch("nhittpc",&nhittpc);
	tree2->Branch("xtpc",xtpc,"xtpc[500]/D");
	tree2->Branch("ytpc",ytpc,"ytpc[500]/D");
	tree2->Branch("ztpc",ztpc,"ztpc[500]/D");


	tree2->Branch("ntTpc",&ntTpc);
	tree2->Branch("nhtrack",&nhtrack);
	tree2->Branch("helix_cx",&helix_cx);
	tree2->Branch("helix_cy",&helix_cy);
	tree2->Branch("helix_dz",&helix_dz);
	tree2->Branch("helix_r",&helix_r);
	tree2->Branch("helix_z0",&helix_z0);
	tree2->Branch("mom0",&mom0);
	tree2->Branch("charge",&charge);
	tree2->Branch("helix_t",&helix_t);
	tree2->Branch("hitpos_x",&hitpos_x);
	tree2->Branch("hitpos_y",&hitpos_y);
	tree2->Branch("hitpos_z",&hitpos_z);
	tree2->Branch("dM",&dM);
	tree2->Branch("MM",&MM);
	tree2->Branch("G4PPhi1",&G4PPhi1);
	tree2->Branch("G4PPhi2",&G4PPhi2);
	tree2->Branch("G4nhKm1",&G4nhKm1);
	tree2->Branch("G4nhKp1",&G4nhKp1);
	tree2->Branch("G4nhKm2",&G4nhKm2);
	tree2->Branch("G4nhKp2",&G4nhKp2);
	tree2->Branch("Km1Len",&Km1Len);
	tree2->Branch("Kp1Len",&Kp1Len);
	tree2->Branch("Km2Len",&Km2Len);
	tree2->Branch("Kp2Len",&Kp2Len);
	

	tree2->Branch("G4tidKm1",&G4tidKm1);
	tree2->Branch("G4PKm1",&G4PKm1);
	tree2->Branch("G4tidKp1",&G4tidKp1);
	tree2->Branch("G4PKp1",&G4PKp1);
	tree2->Branch("G4tidKm2",&G4tidKm2);
	tree2->Branch("G4PKm2",&G4PKm2);
	tree2->Branch("G4tidKp2",&G4tidKp2);
	tree2->Branch("G4PKp2",&G4PKp2);

	tree2->Branch("GoodCombi",&GoodCombi);
	tree2->Branch("FlagPhi1",&FlagPhi1);
	tree2->Branch("GoodPhi1",&GoodPhi1);
	tree2->Branch("InvMPhi1",&InvMPhi1);
	tree2->Branch("cd1",&cd1);
	tree2->Branch("PPhi1",&PPhi1);
	tree2->Branch("PPhi1_x",&PPhi1_x);
	tree2->Branch("PPhi1_y",&PPhi1_y);
	tree2->Branch("PPhi1_z",&PPhi1_z);
	tree2->Branch("tidKm1",&tidKm1);
	tree2->Branch("PKm1",&PKm1);
	tree2->Branch("tidKp1",&tidKp1);
	tree2->Branch("PKp1",&PKp1);
	
	tree2->Branch("FlagPhi2",&FlagPhi2);
	tree2->Branch("GoodPhi2",&GoodPhi2);
	tree2->Branch("InvMPhi2",&InvMPhi2);
	tree2->Branch("cd2",&cd2);
	tree2->Branch("PPhi2",&PPhi2);
	tree2->Branch("PPhi2_x",&PPhi2_x);
	tree2->Branch("PPhi2_y",&PPhi2_y);
	tree2->Branch("PPhi2_z",&PPhi2_z);
	tree2->Branch("tidKm2",&tidKm2);
	tree2->Branch("PKm2",&PKm2);
	tree2->Branch("tidKp2",&tidKp2);
	tree2->Branch("PKp2",&PKp2);
	tree2->Branch("InvMPhi1_Flip",&InvMPhi1_Flip);
	tree2->Branch("InvMPhi2_Flip",&InvMPhi2_Flip);


	for(int i=0;i<ent;++i){
		tree->GetEntry(i);
		Initialize();
		if(i%1000==0) cout<<"Ent  "<<i<<endl;
		if(ntTpc<2){
			tree2->Fill();
			continue;
		}
		for(int it=1;it<=NumberOfTracks;++it){
			int pid = PIDOfTrack[it];
			double pTrack = MomentumOfTrack[it]*0.001;
			if(it == 1) G4PPhi1 = pTrack;
			if(it == 2) G4PPhi2 = pTrack;
			if(abs(pid)!= 321) continue;
			if(pid == -321 and ParentIDOfTrack[it] == 1){
				G4tidKm1 = it;
				G4PKm1 = pTrack;
			}
			if(pid == 321 and ParentIDOfTrack[it] == 1){
				G4tidKp1 = it;
				G4PKp1 = pTrack;
			}
			if(pid == -321 and ParentIDOfTrack[it] == 2){
				G4tidKm2 = it;
				G4PKm2 = pTrack;
			}
			if(pid == 321 and ParentIDOfTrack[it] == 2){
				G4tidKp2 = it;
				G4PKp2 = pTrack;
			}
		}

		vector<Track> Tracks;
		vector<int> G4TrackID;
		vector<int> PureHits;
		for(int it=0;it<ntTpc;++it){
			double p0 = mom0->at(it);
			double hcx = helix_cx->at(it);
			double hcy = helix_cy->at(it);
			double hz0 = helix_z0->at(it);
			double hr = helix_r->at(it);
			int nh = helix_t->at(it).size();
			double ht = helix_t->at(it).at(0);
			double hdz = helix_dz->at(it);
			double par1[5] = {hcx,hcy,hz0,hr,hdz};
			double q1 = charge->at(it);
			int pid = 2;//Kaon
			Tracks.push_back(Track(pid,q1,par1,it,p0,nh,ht));	
			vector<TVector3> TPCHits;
			auto posx = hitpos_x->at(it);
			auto posy = hitpos_y->at(it);
			auto posz = hitpos_z->at(it);
			for(int ih=0;ih<nh;++ih){
				double x = posx.at(ih);
				double y = posy.at(ih);
				double z = posz.at(ih);
				TVector3 TPCHit(x,y,z);
				TPCHits.push_back(TPCHit);
			}
			int nhits = 0;
			int tid = TPCToG4TrackID(TPCHits,nhittpc,ititpc,xtpc,ytpc,ztpc,nhits);
			G4TrackID.push_back(tid);	
			PureHits.push_back(nhits);
		}
		vector<TVector3>Km1Hits;
		vector<TVector3>Km2Hits;
		vector<TVector3>Kp1Hits;
		vector<TVector3>Kp2Hits;
		for(int ih=0;ih<nhittpc;++ih){
			TVector3 tpcHit(xtpc[ih],ytpc[ih],ztpc[ih]);
			int idhit = ititpc[ih];
			if(idhit == G4tidKm1)Km1Hits.push_back(tpcHit); 
			if(idhit == G4tidKp1)Kp1Hits.push_back(tpcHit); 
			if(idhit == G4tidKm2)Km2Hits.push_back(tpcHit); 
			if(idhit == G4tidKp2)Kp2Hits.push_back(tpcHit); 
		};
		Km1Len = Dist(Km1Hits);
		Kp1Len = Dist(Kp1Hits);
		Km2Len = Dist(Km2Hits);
		Kp2Len = Dist(Kp2Hits);
		G4nhKm1 = Km1Hits.size();
		G4nhKp1 = Kp1Hits.size();
		G4nhKm2 = Km2Hits.size();
		G4nhKp2 = Kp2Hits.size();
		vector<Vertex> verts;
		for(int it1=0;it1<ntTpc;++it1){
			Vertex V(Tracks.at(it1));
			V.SetCdCut(cd_cut);
			for(int it2=it1+1;it2<ntTpc;++it2){
				V.AddTrack(Tracks.at(it2));
			}
			verts.push_back(V);
		}
		vector<Recon>PhiCand;



		for(auto V:verts){
			V.SearchPhiCombination();
			auto Cand = V.GetCandidates();
			for (auto cand:Cand)PhiCand.push_back(cand);
		}
		double comp = 9999;
		vector<Recon> Phi;
		for(auto Phi1:PhiCand){
			double MPhi1 = Phi1.Mass();
			int idKm1 = Phi1.GetID1();
			int idKp1 = Phi1.GetID2();
			for(auto Phi2:PhiCand){
				int idKm2 = Phi2.GetID1();
				int idKp2 = Phi2.GetID2();
				if(idKm1 == idKm2 or idKp1 == idKp2) continue;
				double MPhi2 = Phi2.Mass(); 
				dM = hypot(MPhi1-mPhi,MPhi2-mPhi);
				if(dM< comp){
					Phi.clear();	
					comp = dM;
					Phi.push_back(Phi1);
					Phi.push_back(Phi2);
				}
			}
		}
		if(Phi.size()==0){
			for(auto Phi1:PhiCand){
				double MPhi1 = Phi1.Mass();
				int idKm1 = Phi1.GetID1();
				int idKp1 = Phi1.GetID2();
				dM = hypot(MPhi1-mPhi,MPhi1-mPhi);
				if(dM< comp){
					comp = dM;
					Phi.clear();
					Phi.push_back(Phi1);
				}
			}	
		}
		if(Phi.size()==1){
			nPhi = 1;
			auto Phi1 = Phi.at(0); 
			tidKp1 = Phi1.GetID1();
			tidKm1 = Phi1.GetID2();
			int KmId = G4TrackID.at(tidKm1); 
			int KpId = G4TrackID.at(tidKp1); 
			
			if(KmId == G4tidKm1 and KpId == G4tidKp1 ){
				FlagPhi1 = Phi1.Exist();
				InvMPhi1 = Phi1.Mass();
				cd1 = Phi1.GetCD();
				PKm1 = Phi1.GetDaughter(0).Vect().Mag();
				PKp1 = Phi1.GetDaughter(1).Vect().Mag();
				PPhi1 = Phi1.Momentum().Mag();
				PPhi1_x = Phi1.Momentum().X();
				PPhi1_y = Phi1.Momentum().Y();
				PPhi1_z = Phi1.Momentum().Z();
				GoodCombi = true;
				GoodPhi1 = true;
			}
			else if (KmId == G4tidKm2 and KpId == G4tidKp2 ){ 
				FlagPhi2 = Phi1.Exist();
				InvMPhi2 = Phi1.Mass();
				cd2 = Phi1.GetCD();
				PKm2 = Phi1.GetDaughter(0).Vect().Mag();
				PKp2 = Phi1.GetDaughter(1).Vect().Mag();
				PPhi2 = Phi1.Momentum().Mag();
				PPhi2_x = Phi1.Momentum().X();
				PPhi2_y = Phi1.Momentum().Y();
				PPhi2_z = Phi1.Momentum().Z();
				GoodCombi = true;
				GoodPhi2 = true;
			}
			else{
				FlagPhi1 = Phi1.Exist();
				InvMPhi1 = Phi1.Mass();
				cd1 = Phi1.GetCD();
				PKm1 = Phi1.GetDaughter(0).Vect().Mag();
				PKp1 = Phi1.GetDaughter(1).Vect().Mag();
				PPhi1 = Phi1.Momentum().Mag();
				PPhi1_x = Phi1.Momentum().X();
				PPhi1_y = Phi1.Momentum().Y();
				PPhi1_z = Phi1.Momentum().Z();
			}
		}
		if(Phi.size()==2){
			nPhi = 2;
			auto Phi1 = Phi.at(0); 
			auto Phi2 = Phi.at(1); 
			FlagPhi1 = Phi1.Exist();
			FlagPhi2 = Phi2.Exist();
			tidKp1 = Phi1.GetID1();
			tidKm1 = Phi1.GetID2();
			tidKp2 = Phi2.GetID1();
			tidKm2 = Phi2.GetID2();
			int KmId1 = G4TrackID.at(tidKm1); 
			int KpId1 = G4TrackID.at(tidKp1); 
			int KmId2 = G4TrackID.at(tidKm2); 
			int KpId2 = G4TrackID.at(tidKp2); 
			if((KmId1 == G4tidKm1 and KpId1 == G4tidKp1 ) and  (KmId2 == G4tidKm2 and KpId2 == G4tidKp2 )){
				GoodCombi = true;
				GoodPhi1 = true;
				GoodPhi2 = true;
			}
			else if((KmId1 == G4tidKm2 and KpId1 == G4tidKp2 ) and  (KmId2 == G4tidKm1 and KpId2 == G4tidKp1 )){
				GoodCombi = true;
				auto temp = Phi1;
				Phi1 = Phi2;
				Phi2 = temp;
				GoodPhi1 = true;
				GoodPhi2 = true;
				int tempKm = tidKm1;
				int tempKp = tidKp1;
				tidKm1 = tidKm2;
				tidKp1 = tidKp2;
				tidKm2 = tempKm;
				tidKp2 = tempKp;
			}
			else {
				if((KmId1 == G4tidKm1 and KpId1 == G4tidKp1) or KmId1 == G4tidKm2 and KpId1 == G4tidKp2 ) GoodPhi1 = true;
				if((KmId2 == G4tidKm1 and KpId2 == G4tidKp1) or KmId2 == G4tidKm2 and KpId2 == G4tidKp2 ) GoodPhi2 = true;
			}
			InvMPhi1 = Phi1.Mass();
			cd1 = Phi1.GetCD();
			PKm1 = Phi1.GetDaughter(0).Vect().Mag();
			PKp1 = Phi1.GetDaughter(1).Vect().Mag();
			PPhi1 = Phi1.Momentum().Mag();
			PPhi1_x = Phi1.Momentum().X();
			PPhi1_y = Phi1.Momentum().Y();
			PPhi1_z = Phi1.Momentum().Z();
		
			InvMPhi2 = Phi2.Mass();
			cd2 = Phi2.GetCD();
			PKm2 = Phi2.GetDaughter(0).Vect().Mag();
			PKp2 = Phi2.GetDaughter(1).Vect().Mag();
			PPhi2 = Phi2.Momentum().Mag();
			PPhi2_x = Phi2.Momentum().X();
			PPhi2_y = Phi2.Momentum().Y();
			PPhi2_z = Phi2.Momentum().Z();
			TLorentzVector LVPB(0,0,mom,hypot(mp,mom));
			TLorentzVector LVP(0,0,0,hypot(mp,0));
			if(conf == 3){
				LVP = TLorentzVector(0,0,0,hypot(md,0));
			}
			auto Target = LVPB+LVP;
			auto LVPhi1 = Phi1.GetLV();
			auto LVPhi2 = Phi2.GetLV();
			MM = Target.Mag()- (LVPhi1 + LVPhi2).Mag();
//			MM = (Target- (LVPhi1 + LVPhi2)).Mag();
			if(conf == 3){
				LVP = TLorentzVector(0,0,0,hypot(md,0));
				Target = LVPB+LVP;
				LVPhi1 = Phi1.GetLV();
				LVPhi2 = Phi2.GetLV();
				MM = (Target- (LVPhi1 + LVPhi2)).Mag();
			}
			for(auto Phi1:PhiCand){
				if(Phi1.GetID1() == tidKp1 and Phi1.GetID2() == tidKm2){
					InvMPhi1_Flip = Phi1.Mass();
				}
				if(Phi1.GetID1() == tidKp2 and Phi1.GetID2() == tidKm1){
					InvMPhi2_Flip = Phi1.Mass();
				}
			}

		}//PhiSize == 2;
		tree2->Fill();
	}//iev
	file2->Write();
	cout<<tree2->GetEntries()<<endl;
	
}
void G4PhiAnal(){
	if(conf == 0){
		filename = Form("PhiProd/PPBarPhi_%gGeV_DstTPCTrackingHelixGeant4.root",mom);
		filename2= Form("PPBarPhiAnal_%gGeV_cd%g.root",mom,cd_cut);
	}
	else if(conf == 1){
		filename = Form("PhiProd/PPBar2PiPhi_%gGeV_DstTPCTrackingHelixGeant4.root",mom);
		filename2= Form("PPBar2PiPhiAnal_%gGeV_cd%g.root",mom,cd_cut);
	}
	else if(conf == 2){
		filename = Form("PhiProd/PPBar4Pi_%gGeV_DstTPCTrackingHelixGeant4.root",mom);
		filename2= Form("PPBar4PiAnal_%gGeV_cd%g.root",mom,cd_cut);
	}
	else if(conf == 3){
		filename = Form("PhiProd/DPBarFermi_%gGeV_DstTPCTrackingHelixGeant4.root",mom);
		filename2= Form("DPBarFermiAnal_%gGeV_cd%g.root",mom,cd_cut);
	}
	file = new TFile(filename);
	tree = (TTree*)file->Get("tpc");
	tree->SetBranchAddress("nhHtof",&nhHtof);
	tree->SetBranchAddress("yHtof",yHtof);
	tree->SetBranchAddress("didHtof",didHtof);
	tree->SetBranchAddress("nhittpc",&nhittpc);
	tree->SetBranchAddress("ititpc",ititpc);
	tree->SetBranchAddress("xtpc",xtpc);
	tree->SetBranchAddress("ytpc",ytpc);
	tree->SetBranchAddress("ztpc",ztpc);
	
	tree->SetBranchAddress("NumberOfTracks",&NumberOfTracks);
	tree->SetBranchAddress("PIDOfTrack",PIDOfTrack);
	tree->SetBranchAddress("ParentIDOfTrack",ParentIDOfTrack);
	tree->SetBranchAddress("MomentumOfTrack",MomentumOfTrack);

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
	tree->SetBranchAddress("hitpos_x",&hitpos_x);
	tree->SetBranchAddress("hitpos_y",&hitpos_y);
	tree->SetBranchAddress("hitpos_z",&hitpos_z);
	G4PhiAnal(0);
}
