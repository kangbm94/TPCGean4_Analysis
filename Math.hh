#ifndef Math_hh
#define Math_hh 1
double XiParam[2] = {-0.401,-2.1};
double AXi = XiParam[0];
double BXi = sqrt(1 - AXi*AXi) * sin(XiParam[1]*acos(-1)/180);
double CXi = sqrt(1 - AXi*AXi) * cos(XiParam[1]*acos(-1)/180);

double LdParam[2] = {0.732,-6.5};
double ALd = LdParam[0];
double BLd = sqrt(1 - ALd*ALd) * cos(LdParam[1]*acos(-1)/180);
double CLd = sqrt(1 - ALd*ALd) * sin(LdParam[1]*acos(-1)/180);
double mP = .938272;

TVector3 NormalCross(TVector3 A, TVector3 B){
	auto C = A.Cross(B);
	C = C*(1./C.Mag());
	return C;
}
double NormalDot(TVector3 A, TVector3 B){
	auto nA = A.Mag();
	auto nB = B.Mag();
	return A*B / nA / nB;
}

double MeV = 1000;
TLorentzVector ToHelix(TLorentzVector B){
		double x = -B.X();
		double y = B.Z();
		double z = B.Y();
		double t = B.T();
		return TLorentzVector(x,y,z,t);
}
TVector3 ToHelix(TVector3 B){
		double x = -B.X();
		double y = B.Z();
		double z = B.Y();
		return TVector3(x,y,z);
}
TVector3 ToGlobal(TVector3 B){
		double x = -B.X();
		double y = B.Z();
		double z = B.Y();
		return TVector3(x,y,z);
}
TMatrixD MinorMatrix(TMatrixD A,int row, int col){
	int Arow = A.GetNrows();
	int Acol = A.GetNcols();
	if(row < 0 or row > Arow -1 or col > Acol -1 or col < 0){
		cout<<"Failed to get Minor:";
		A.Print();
		return A; 
	}
	TMatrixD B(Arow-1,Acol-1);
	int Brow = 0;
	for(int ir = 0;ir < Arow; ++ir){
		if(ir == row) continue;
		int Bcol = 0;
		for(int ic = 0;ic < Acol; ++ic){
			if(ic == col) continue;
			B(Brow,Bcol) = A(ir,ic);
			Bcol++;
		}
		Brow++;
	}
	return B;
}
double ResP(double* res,double* par){
/*
 For a Multivariable function F of Ms, F(M), 
 the Covariance of F, V(F) should satisfy
 V(F) = J^T V(M) J, where J = dFdM is a Jacobian of F respect to M.
	Here, We set F = P = abs(Pt*1/sin(th));
	and obtain the Variance of P from Pt,Th,Ph.
 */
	double VPt = res[0]*res[0];
	double VTh = res[1]*res[1];
	double VPh = res[2]*res[2];

	double Pt = par[0];
	double Th = par[1];
	double Ph = par[2];
	double k = cos(Th);
	double dPdPt = 1./abs(sin(Th));
	double dPdTh = Pt*cos(Th)/sin(Th)/sin(Th);
	double dPdPh = 0;
	/*	
	double dPt2 = j*j/(1-j*j); //Square of Derivatives of Py respect to Pt;
	double dTh2 = Pt*Pt*pow((1-2*j*j),2)/pow(1-j*j,3)*pow(cos(Th)*sin(Ph),2);//Square of Derivatives of Py respect to Th;
	double dPh2 = Pt*Pt*pow((1-2*j*j),2)/pow(1-j*j,3)*pow(sin(Th)*cos(Th),2);//Square of Derivatives of Py respect to Th;
*/
//	double VPy = VPt * dPt2 + VTh * dTh2 + VPh * dPh2;
//	double VP = VPy + VPt;
	double dPt2  = dPdPt*dPdPt;
	double dTh2  = dPdTh*dPdTh;
	double dPh2  = dPdPh*dPdPh;
	double VP = VPt * dPt2 + VTh * dTh2 + VPh * dPh2;
	return sqrt(VP);
}


void CovThPh(double* res, double* par, double* cov){
	//* Theta and phi in global coordinate
	// will be respresented in terms of helix coordinate:
	// (x,y,z) -> (z,-x,y) where
	// x = r sin(Th)cos(Ph) = -r sin(th)sin(ph)
	// y = r sin(Th)sin(Ph) = r cos(th)
	// z = r cos(Th) = rsin(th)cos(ph)
	// where th = acos( y/r ) = acos[sin(Th)sin(Ph)]
	// and ph = atan2( -x/z ) = atan2[ sin(Th)cos(Ph) / cos(Th) ] = atan2[ tan(Th)cos(Ph)];
	// Then, Th = acos( z/r ) = acos[ sin(th)cos(ph)]
	// and Ph = atan2( y/x) = atan2[cos(th)/sin(th)/sin(ph)] = atan2[cot(th)/sin(ph)]
	// Then the covariance will be
	// V(Th,Ph) = J^T V(th,ph) J  where J = (dTh/dth , dTh/dph)
	// 																			(dPh/dth , dPh/dph)
	//and we have dTh/dth = - cos(th)sin(ph)/sqrt(1-sin^2(th)sin^2(ph));
	//						dTh/dph = - sin(th)cos(ph)/sqrt(1-sin^2(th)sin^2(ph));
	//						dPh/dth = cos(ph)/(sin^2 ph + cot^2 th);
	//						dPh/dph = cot(th)/(sin^2 ph + cot^2 th);
	double sth=res[0];
	double sph=res[1];
	
	double th=par[0];
	double ph=par[1];
	double dTdt = - cos(th)*sin(ph) / sqrt(1 - pow(sin(th)*sin(ph),2));
	double dTdp = - sin(th)*cos(ph) / sqrt(1 - pow(sin(th)*sin(ph),2));
	double dPdt = cos(ph) / (sin(ph)*sin(ph)+1./tan(th)/tan(th));
	double dPdp = 1./ (sin(ph)*sin(ph)+1./tan(ph)/tan(ph)) / tan(th)/tan(th);

	double VJ11 = sth*dTdt;
	double VJ12 = sth*dTdp;
	double VJ21 = sph*dPdt;
	double VJ22 = sph*dPdp;

	double VTVJ11 = dTdt*VJ11 + dPdt*VJ21;
	double VTVJ12 = dTdt*VJ12 + dPdt*VJ22;
	double VTVJ21 = dTdp*VJ11 + dPdp*VJ21;
	double VTVJ22 = dTdp*VJ12 + dPdp*VJ22;

	cov[0] = VTVJ11;
	cov[1] = VTVJ12;
	cov[2] = VTVJ21;
	cov[3] = VTVJ22;
}
void WeightedFill(TH1D* h,double dat, double w){
	int bin = h->FindBin(dat);
	h->AddBinContent(bin,w);
}
int GetBin(int nbin, double lb,double hb, double cont){
	double bw = (hb - lb)/nbin;
	double range = cont - lb;
	int bin = floor(range / bw);
	if (bin<0) return -1;
	if (bin >= nbin) return nbin;
	else return bin;
}
double GetBinCenter(int nbin, double lb, double hb, int bin){
	double bw = (hb - lb)/nbin;
	double offset = lb + bw/2; 
	if(bin < 0) return lb - bw/2;
	if(bin >= nbin) return hb + bw/2;
	return offset + bw * bin;	
}
double GetBField(double pt, double rad){
	double Const = 0.299792458;
	return pt / rad / Const;
}
double GetRad(double pt, double B){
	double Const = 0.299792458;
	return pt / B / Const;
}
double GetL(double rad, double path){
	double angle = abs(path) / rad / 2;
	return 2 * sin(angle) * rad;
}
double MomTRes(int nh, vector<double>rest, double pt, double rad, double path){
	double B = GetBField(pt,rad);
	double L = GetL(rad,path);
	double res = 0;
	for(auto r:rest){
		if(r > 1e2) nh--;
		else res+= r*r;
	}
	res = sqrt(3./2)*sqrt( res / nh);
	double r_geom =  pt/(0.3*L*L*B)*sqrt(720./(nh+4))*res; 
	return r_geom;
//	double r_scat = ;
}
double RadRes(double res_pt,double rad){
	return res_pt*rad;
}
double PhiRes(double res_pt,double rad, double path){
	double res_rad = RadRes(res_pt,rad);	
	return path * res_rad /rad/rad/2;
}


double ThetaRes(int nh, vector<double> resy,double path, double th){
	double res2 = 0;
	for(auto r:resy){
		if(r > 1e2) nh--;
		else res2+= r*r;
	}
	if(nh < 3) nh = 3;
	double path_dev = path * path* nh / 12.;
	double sig_slope = 1./(nh-2) * res2 / path_dev;
	sig_slope = sqrt(sig_slope);
	//slope = cot(Th);
	//dTh = acot(slope) * dSlope = dSlope /(1+Th^2);
	double sl = tan(0.5*acos(-1) - th); 
	return sig_slope * 1./(1+sl*sl);	
}

TF1* fGaus = new TF1("fGaus","gaus",-100,100);
TLorentzVector SwapYZ(TLorentzVector A){
	double Y = A.Y();
	double Z = A.Z();
	A.SetZ(Y);
	A.SetY(Z);
	return A;
}


#endif
