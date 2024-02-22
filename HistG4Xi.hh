int nbin_pol = 100;
TH1D* HistG4PolTh = new TH1D("G4#theta","G4#theta",nbin_pol,-1.,1.);
TH1D* HistG4PolPha = new TH1D("G4#phia","G4#phia",nbin_pol,-1.,1.);
TH1D* HistG4PolPhb = new TH1D("G4#phib","G4#phib",nbin_pol,-1.,1.);
TH1D* HistG4PolPhc = new TH1D("G4#phic","G4#phic",nbin_pol,-1.,1.);
TH1D* HistPolTh = new TH1D("#theta","#theta",nbin_pol,-1.,1.);
TH1D* HistPolPha = new TH1D("#phiia","#phiia",nbin_pol,-1.,1.);
TH1D* HistPolPhb = new TH1D("#phiib","#phiib",nbin_pol,-1.,1.);
TH1D* HistPolPhc = new TH1D("#phiic","#phiic",nbin_pol,-1.,1.);

int nbin = 100;
TH1D* HistXiDist = new TH1D("XiDist","XiDist",nbin,0,200);
TH1D* HistLdDist = new TH1D("LdDist","LdDist",nbin,0,200);

int nbin_p = 200;
int nbin_th = 200;

TH1D* HistPMomtRes = new TH1D("PMomtRes","PMomtRes",nbin_p,0,0.3);
TH1D* HistPi1MomtRes = new TH1D("#pi1MomtRes","#pi1MomtRes",nbin_p,0,0.3);
TH1D* HistPi2MomtRes = new TH1D("#pi2MomtRes","#pi2MomtRes",nbin_p,0,0.3);

TH1D* HistXiMomtResi = new TH1D("XiMomtResi","XiMomtResi",nbin_p,-1,1);
TH1D* HistLdMomtResi = new TH1D("LdMomtResi","LdMomtResi",nbin_p,-1,1);
TH1D* HistPMomtResi = new TH1D("PMomtResi","PMomtResi",nbin_p,-1,1);
TH1D* HistPi1MomtResi = new TH1D("#pi1MomtResi","#pi1MomtResi",nbin_p,-0.3,0.3);
TH1D* HistPi2MomtResi = new TH1D("#pi2MomtResi","#pi2MomtResi",nbin_p,-0.3,0.3);

TH1D* HistXiMomtKFResi = new TH1D("XiMomtKFResi","XiMomtKFResi",nbin_p,-1,1);
TH1D* HistLdMomtKFResi = new TH1D("LdMomtKFResi","LdMomtKFResi",nbin_p,-1,1);
TH1D* HistPMomtKFResi = new TH1D("PMomtKFResi","PMomtKFResi",nbin_p,-1,1);
TH1D* HistPi1MomtKFResi = new TH1D("#pi1MomtKFResi","#pi1MomtKFResi",nbin_p,-0.3,0.3);
TH1D* HistPi2MomtKFResi = new TH1D("#pi2MomtKFResi","#pi2MomtKFResi",nbin_p,-0.3,0.3);

TH1D* HistPMomtPull = new TH1D("PMomtPull","PMomtPull",nbin,-5,5);
TH1D* HistPi1MomtPull = new TH1D("#pi1MomtPull","#pi1MomtPull",nbin,-5,5);
TH1D* HistPi2MomtPull = new TH1D("#pi2MomtPull","#pi2MomtPull",nbin,-5,5);

double angle_range= 0.1;
double theta_range= 0.03;
double angle_pull= 5;
TH1D* HistXiPhResi = new TH1D("Xi#phiResi","Xi#phiResi",nbin_th,-angle_range,angle_range);
TH1D* HistXiThResi = new TH1D("Xi#thetaResi","Xi#thetaResi",nbin_th,-theta_range,theta_range);
TH1D* HistLdPhResi = new TH1D("Ld#phiResi","Ld#phiResi",nbin_th,-angle_range,angle_range);
TH1D* HistLdThResi = new TH1D("Ld#thetaResi","Ld#thetaResi",nbin_th,-2*theta_range,2*theta_range);

TH1D* HistPPhResi = new TH1D("P#phiResi","P#phiResi",nbin_th,-angle_range,angle_range);
TH1D* HistPThResi = new TH1D("P#thetaResi","P#thetaResi",nbin_th,-theta_range,theta_range);
TH1D* HistPi1PhResi = new TH1D("#pi1#phiResi","#pi1#phiResi",nbin_th,-angle_range,angle_range);
TH1D* HistPi1ThResi = new TH1D("#pi1#thetaResi","#pi1#thetaResi",nbin_th,-theta_range,theta_range);
TH1D* HistPi2PhResi = new TH1D("#pi2#phiResi","#pi1#phiResi",nbin_th,-angle_range,angle_range);
TH1D* HistPi2ThResi = new TH1D("#pi2#thetaResi","#pi2#thetaResi",nbin_th,-theta_range,theta_range);

TH1D* HistLdPhKFResi = new TH1D("Ld#phiKFResi","Ld#phiKFResi",nbin_th,-angle_range,angle_range);
TH1D* HistLdThKFResi = new TH1D("Ld#thetaKFResi","Ld#thetaKFResi",nbin_th,-2*theta_range,2*theta_range);
TH1D* HistPPhKFResi = new TH1D("P#phiKFResi","P#phiKFResi",nbin_th,-angle_range,angle_range);
TH1D* HistPThKFResi = new TH1D("P#thetaKFResi","P#thetaKFResi",nbin_th,-theta_range,theta_range);
TH1D* HistPi1PhKFResi = new TH1D("#pi1#phiKFResi","#pi1#phiKFResi",nbin_th,-angle_range,angle_range);
TH1D* HistPi1ThKFResi = new TH1D("#pi1#thetaKFResi","#pi1#thetaKFResi",nbin_th,-theta_range,theta_range);
TH1D* HistPi2PhKFResi = new TH1D("#pi2#phiKFResi","#pi1#phiKFResi",nbin_th,-angle_range,angle_range);
TH1D* HistPi2ThKFResi = new TH1D("#pi2#thetaKFResi","#pi2#thetaKFResi",nbin_th,-theta_range,theta_range);








TH1D* HistPPhRes = new TH1D("P#phiRes","P#phiRes",nbin_th,0,angle_range);
TH1D* HistPThRes = new TH1D("P#thetaRes","P#thetaRes",nbin_th,0,angle_range);
TH1D* HistPi1PhRes = new TH1D("#pi1#phiRes","#pi1#phiRes",nbin_th,0,angle_range);
TH1D* HistPi1ThRes = new TH1D("#pi1#thetaRes","#pi1#thetaRes",nbin_th,0,angle_range);
TH1D* HistPi2PhRes = new TH1D("#pi2#phiRes","#pi1#phiRes",nbin_th,0,angle_range);
TH1D* HistPi2ThRes = new TH1D("#pi2#thetaRes","#pi2#thetaRes",nbin_th,0,angle_range);

TH1D* HistPPhPull = new TH1D("P#phiPull","P#phiPull",nbin_th,-angle_pull,angle_pull);
TH1D* HistPThPull = new TH1D("P#thetaPull","P#thetaPull",nbin_th,-angle_pull,angle_pull);
TH1D* HistPi1PhPull = new TH1D("#pi1#phiPull","#pi1#phiPull",nbin_th,-angle_pull,angle_pull);
TH1D* HistPi1ThPull = new TH1D("#pi1#thetaPull","#pi1#thetaPull",nbin_th,-angle_pull,angle_pull);
TH1D* HistPi2PhPull = new TH1D("#pi2#phiPull","#pi2#phiPull",nbin_th,-angle_pull,angle_pull);
TH1D* HistPi2ThPull = new TH1D("#pi2#thetaPull","#pi2#thetaPull",nbin_th,-angle_pull,angle_pull);

int nbin_KFPull = 100;
TH1D* HistPMomKFPull = new TH1D("PMomKFPull","PMomKFPull",nbin_KFPull,-5,5);
TH1D* HistPThKFPull = new TH1D("P#thetaKFPull","P#thetaKFPull",nbin_KFPull,-5,5);
TH1D* HistPPhKFPull = new TH1D("P#phiKFPull","P#phiKFPull",nbin_KFPull,-5,5);
TH1D* HistPi1MomKFPull = new TH1D("#pi1MomKFPull","#pi1MomKFPull",nbin_KFPull,-5,5);
TH1D* HistPi1ThKFPull = new TH1D("#pi1#thetaKFPull","#pi1#thetaKFPull",nbin_KFPull,-5,5);
TH1D* HistPi1PhKFPull = new TH1D("#pi1#phiKFPull","#pi1#phiKFPull",nbin_KFPull,-5,5);



TH1D* HistXiMass = new TH1D("XiMass","XiMass",500,1.3,1.34);
TH1D* HistXiMassKF = new TH1D("XiMassKF","XiMassKF",500,1.3,1.34);
TH1D* HistXiMassCor = new TH1D("XiMassCor","XiMassCor",500,1.3,1.34);

TH1D* HistLdKFChi2 = new TH1D("KFLdChi2","KFLdChi2",100,0,10);
TH1D* HistLdKFCL = new TH1D("KFLdCL","KFLdCL",102,-0.01,1.01);

void GenerateHists(){
}




