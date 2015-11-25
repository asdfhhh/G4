/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2014-09-16 10:06
* Filename: fit.cc
* Description: 
*************************************************/
void fit() 
{
	gROOT->ProcessLine(".L bethe.cc");
	TFile*f=new TFile("results.root");
	Double_t params[2]={1E7,7.5E-3};   
	TF1 *bf = new TF1("bf",bethe,10000,30000,2);
	bf->SetParameters(params);
	dE1E->Draw();
	TProfile*p=dE1E->ProfileX();
	p->Fit("bf","R","SAME",10000,30000);	
}
