/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2014-09-16 14:22
* Filename: bethe.cc
* Description: 
*************************************************/
Double_t bethe(Double_t *x, Double_t *par)
{
        Double_t result = par[0]*TMath::Log(par[1]*x[0])/x[0];
	return result;
}

