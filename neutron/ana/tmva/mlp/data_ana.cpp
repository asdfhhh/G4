/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2014-09-04 17:15
* Filename:		data_ana.cpp
* Description: 
*************************************************/
#include "ParticleDis.h"
#include "TFile.h"
#include "TTree.h"
#include <iostream>
#include "TH1F.h"
#include "TApplication.h"
using namespace std;
int main(int argc, char **argv)
{
	// create an instance of TApplication
	TApplication*gMyRootApp = new TApplication("My ROOT Application", &argc, argv);
 	double type=0;
	int trut=0;
	// tell application to return from run
	gMyRootApp->SetReturnFromRun(true);
	TFile *input = 0;
	input = TFile::Open("Data_1.root");
	ParticleDis*mlp=new ParticleDis();
	TTree *signal = (TTree *) input->Get("truth");

	Double_t t_Ch1, t_Ch2, t_Ch3;
	signal->SetBranchAddress("t_Ch1", &t_Ch1);
	signal->SetBranchAddress("t_Ch2", &t_Ch2);
	signal->SetBranchAddress("t_Ch3", &t_Ch3);

        TFile*newfile=new TFile("results.root","recreate");
        TTree *output = new TTree("output", "mpl output");
        output->Branch("type", &type, "type/D");
        output->Branch("trut", &trut, "trut/I");
        output->Branch("t_Ch1", &t_Ch1, "t_Ch1/D");
        output->Branch("t_Ch2", &t_Ch2, "t_Ch2/D");
        output->Branch("t_Ch3", &t_Ch3, "t_Ch3/D");

	TH1F*f=new TH1F("PID","particle identify",50,-5,5);
	for (int i = 0; i < signal->GetEntries(); i++)
	{
		trut=i%5;
		signal->GetEntry(i);
		type=mlp->Value(0,t_Ch1, t_Ch2, t_Ch3);
		f->Fill(type-trut);
		output->Fill();
	}
	output->Write();
	f->Write();
	//gMyRootApp->Run();
	return 1;
}
