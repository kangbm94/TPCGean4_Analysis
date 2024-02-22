#include "./KpXiPol/tpc.h"
double pmom_t,G4pmom_t,ppath;
double res_pmom_t,resi_pmom_t;
double pi1mom_t,G4pi1mom_t,pi1path;
double res_pi1mom_t,resi_pi1mom_t;
double pi2mom_t,G4pi2mom_t,pi2path;
double res_pi2mom_t,resi_pi2mom_t;
double res_Ldmom,res_LdTh,res_LdPh;


double Ldmom,Ldmom_x,Ldmom_y,Ldmom_z,Ldmom_t,LdTh,LdPh;
double G4Ldmom,G4Ldmom_x,G4Ldmom_y,G4Ldmom_z,G4Ldmom_t,G4LdTh,G4LdPh;


double KFpmom,KFpmom_x,KFpmom_y,KFpmom_z,KFpmom_t;
double KFpi1mom,KFpi1mom_x,KFpi1mom_y,KFpi1mom_z,KFpi1mom_t;
double KFpi2mom,KFpi2mom_x,KFpi2mom_y,KFpi2mom_z,KFpi2mom_t;
double KFLdmom,KFLdmom_x,KFLdmom_y,KFLdmom_z,KFLdmom_t;
double KFXimom,KFXimom_x,KFXimom_y,KFXimom_z,KFXimom_t;
double KFLdTh,KFLdPh;
double KFXiTh,KFXiPh;


double pPh,pTh,G4pPh,G4pTh,KFpPh,KFpTh;
double res_pPh,res_pTh,resi_pPh,resi_pTh;
double pi1Ph,pi1Th,G4pi1Ph,G4pi1Th,KFpi1Ph,KFpi1Th;
double res_pi1Ph,res_pi1Th,resi_pi1Ph,resi_pi1Th;
double pi2Ph,pi2Th,G4pi2Ph,G4pi2Th,KFpi2Ph,KFpi2Th;
double res_pi2Ph,res_pi2Th,resi_pi2Ph,resi_pi2Th;

double Chi2Ld,CLLd;
double XiMassLdKF;
double Chi2Xi,CLXi;

TTree* tree_out;
