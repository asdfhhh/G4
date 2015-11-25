/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2014-09-04 17:11
* Filename:		mlp.cc
* Description: 
*************************************************/
void mlp(Int_t ntrain=100)
{
	if (!gROOT->GetClass("TMultiLayerPerceptron"))
	{
		gSystem->Load("libMLP");
	}

	const char *fname = "Data_0.root";
	TFile *input = 0;
	input = TFile::Open(fname);
	if (!input) return;

	TTree *signal = (TTree *) input->Get("truth");

	Double_t t_Ch1, t_Ch2, t_Ch3;
	Int_t type;
	signal->SetBranchAddress("t_Ch1", &t_Ch1);
	signal->SetBranchAddress("t_Ch2", &t_Ch2);
	signal->SetBranchAddress("t_Ch3", &t_Ch3);
 
	TFile*newfile=new TFile("results.root","recreate");
	TTree *simu = new TTree("simu", "mpl Events");
	simu->Branch("t_Ch1", &t_Ch1, "t_Ch1/D");
	simu->Branch("t_Ch2", &t_Ch2, "t_Ch2/D");
	simu->Branch("t_Ch3", &t_Ch3, "t_Ch3/D");
	simu->Branch("type",  &type,   "type/I");
	Int_t i;
	for (i = 0; i < signal->GetEntries(); i++)
	{
		if(i%5)type=0;
		else type=1;
		signal->GetEntry(i);
		simu->Fill();
	}
   // Build and train the NN ptsumf is used as a weight since we are primarly 
   // interested  by high pt events.
   // The datasets used here are the same as the default ones.
	TMultiLayerPerceptron *mlp = 
		new TMultiLayerPerceptron("@t_Ch1,@t_Ch2,@t_Ch3:5:3:type",simu);
	mlp->Train(ntrain, "text,graph,update=10");
	mlp->Export("ParticleDis","C++");
   // Use TMLPAnalyzer to see what it looks for
	TCanvas* mlpa_canvas = new TCanvas("mlpa_canvas","Network analysis");
	mlpa_canvas->Divide(2,2);
	TMLPAnalyzer ana(mlp);
   // Initialisation
	ana.GatherInformations();
   // output to the console
	ana.CheckNetwork();
	mlpa_canvas->cd(1);
   // shows how each variable influences the network
	ana.DrawDInputs();
	mlpa_canvas->cd(2);
   // shows the network structure
	mlp->Draw();
	mlpa_canvas->cd(3);
   // draws the resulting network
	ana.DrawNetwork(0,"type==0","type==1");
	/*mlpa_canvas->cd(4);
   // Use the NN to plot the results for each sample
   // This will give approx. the same result as DrawNetwork.
   // All entries are used, while DrawNetwork focuses on 
   // the test sample. Also the xaxis range is manually set.
   TH1F *bg = new TH1F("bgh", "NN output", 50, -.5, 1.5);
   TH1F *sig = new TH1F("sigh", "NN output", 50, -.5, 1.5);
   bg->SetDirectory(0);
   sig->SetDirectory(0);
   Double_t params[4];
   for (i = 0; i < background->GetEntries(); i++) {
      background->GetEntry(i);
      params[0] = msumf;
      params[1] = ptsumf;
      params[2] = acolin;
      params[3] = acopl;
      bg->Fill(mlp->Evaluate(0, params));
   }
   for (i = 0; i < signal->GetEntries(); i++) {
      signal->GetEntry(i);
      params[0] = msumf;
      params[1] = ptsumf;
      params[2] = acolin;
      params[3] = acopl;
      sig->Fill(mlp->Evaluate(0,params));
   }
   bg->SetLineColor(kBlue);
   bg->SetFillStyle(3008);   bg->SetFillColor(kBlue);
   sig->SetLineColor(kRed);
   sig->SetFillStyle(3003); sig->SetFillColor(kRed);
   bg->SetStats(0);
   sig->SetStats(0);
   bg->Draw();
   sig->Draw("same");
   TLegend *legend = new TLegend(.75, .80, .95, .95);
   legend->Adt_Chntry(bg, "Background (WW)");
   legend->Adt_Chntry(sig, "Signal (Higgs)");
   legend->Draw();
   mlpa_canvas->cd(0);*/
	simu->Write();
	delete input;
	delete newfile;
}
