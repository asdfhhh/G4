Double_t signalf(Double_t *x, Double_t *par)
{
	double Q = 100;
	//make the position dependen
	//electrons and holes drift time wiht mobility 1000/50 cm2/Vs;voltage 300V; 0.3cm thickness
	double v_e=par[1]*par[5]/par[0];
	double v_h=par[2]*par[5]/par[0];        
	double t_e=(par[0]/2+x[1])/v_e;
	double t_h=(par[0]/2-x[1])/v_h;
	//charge induced by electrons and holes with lifetime 3E-6s and 1E-6s
	if(x[0]>t_e)double I_e=0;
	else double Q_e=Q*par[3]*v_e*(1-TMath::Exp(-x[0]/par[3]))/par[0];
	if(x[0]>t_h)double I_h=0;
	else double Q_h=Q*par[4]*v_h*(1-TMath::Exp(-x[0]/par[4]))/par[0];
	//get total
	Q = Q_e+Q_h;
	return Q;
}

void drawsignal2() {
	TCanvas *c1 = new TCanvas("c1","Draw the CZT signal",200,10,700,500);
// Creates a Root function based on function fitf above
	TF2 *func = new TF2("signal",signalf,0,3E-6,-0.15,0.15,6);

// Sets initial values and parameter names
	func->SetParameters(0.3,1000,50,3E-6,1E-6,300);
	func->SetParNames("DetThickness","EMobi","HMobi","ELife","HLife","HV");
//Draw the Function
	func->Draw("SURF2");
}
