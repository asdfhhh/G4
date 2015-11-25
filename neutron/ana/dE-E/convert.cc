/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-02-02 12:30
* Filename:		convert.cc
* Description: 
*************************************************/
{
	TFile *input = 0;
	input = TFile::Open("Data_0.root");
	TTree *signal = (TTree *) input->Get("truth");
	Double_t t_Ch1, t_Ch2, t_Ch3, t_Ch4;
	signal->SetBranchAddress("t_Ch1", &t_Ch1);
	signal->SetBranchAddress("t_Ch2", &t_Ch2);
	signal->SetBranchAddress("t_Ch3", &t_Ch3);
        signal->SetBranchAddress("t_Ch4", &t_Ch4);

        TFile*newfile=new TFile("results.root","recreate");
	Double_t E=0;
	Double_t dE1=0;
        Double_t dE2=0;
        Double_t dE3=0;
	int type=0;
	int endp=0;
        TTree *output = new TTree("output", "de-e output");
        output->Branch("type", &type, "type/I");
        output->Branch("dE1", &dE1, "dE1/D");
        output->Branch("dE2", &dE2, "dE2/D");
        output->Branch("dE3", &dE3, "dE3/D");
        output->Branch("E", &E, "E/D");
        output->Branch("endp", &endp, "endp/I");
	for (int i = 0; i < signal->GetEntries(); i++)
	{
		type=i%5;
		signal->GetEntry(i);
		E=t_Ch1+t_Ch2+t_Ch3+t_Ch4;
		dE1=t_Ch1;
		dE2=t_Ch2;
		dE3=t_Ch3;
		endp=0;
		if (t_Ch2==0)endp=1;
		else if(t_Ch3==0) endp=2;
		else if(t_Ch4==0) endp=3;
		else if(t_Ch4!=0) endp=4;
		output->Fill();
	}
	output->Write();
}
