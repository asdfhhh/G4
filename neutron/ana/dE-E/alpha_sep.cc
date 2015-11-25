/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2014-09-17 14:51
* Filename:		alpha_sep.cc
* Description: 
*************************************************/
{
	TFile*f=new TFile("results.root");
        TTree *output = (TTree *) f->Get("output");
	Double_t E=0;
        Double_t dE1=0;
        Double_t dE2=0;
        int type=0;
        int endp=0;
        output->SetBranchAddress("type", &type);
        output->SetBranchAddress("dE1", &dE1);
        output->SetBranchAddress("dE2", &dE2);
        output->SetBranchAddress("E", &E);
        output->SetBranchAddress("endp", &endp);
	TH2F*tmp[5][3];
	char name[100];
	for (int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			sprintf(name,"p%de%d",i,j);
			tmp[i][j]=new TH2F(name,name,1000,0,30000,1000,0,output->GetMaximum("dE2"));
		}
	}
        for (int i = 0; i < output->GetEntries(); i++)
        {
		output->GetEntry(i);
		if(endp==3){tmp[type][0]->Fill(E,dE1);
                tmp[type][1]->Fill(E,dE2);}
                if(endp==2)tmp[type][2]->Fill(dE2,dE1);
	}
	TH2F*He[3];
	He[0]=new TH2F("He1","He separation of dE1 v E",100,5000,30000,100,0,100);
        He[1]=new TH2F("He2","He separation of dE2 v E",100,5000,30000,100,0,100);
        He[2]=new TH2F("He3","He separation of dE1 v dE2",100,0,10000,100,0,100);
	TProfile*p[3];
	double sep=0;
	double res=0;
	double ax=0;
	int j=0;
	TTree*t=new TTree("new","new");
	t->Branch("sep",&sep,"sep/D");
        t->Branch("res",&res,"res/D");
	t->Branch("ax",&ax,"ax/D");
	t->Branch("type",&j,"type/I");
	for(;j<3;j++)
	{
		p[0]=tmp[0][j]->ProfileX();
	        p[1]=tmp[4][j]->ProfileX();
		int nbins = p[0]->GetXaxis()->GetNbins();
		for(int i=0;i<nbins;i++)
		{
			sep=(p[0]->GetBinContent(i))-(p[1]->GetBinContent(i));
			res=(p[0]->GetBinError(i)+p[1]->GetBinError(i))/2;
			ax=p[0]->GetXaxis()->GetBinCenter(i);
			He[j]->Fill(p[0]->GetXaxis()->GetBinCenter(i),sep/res);
			t->Fill();
		}
	}
	for(int i=0;i<3;i++)
	{
		p[i]=He[i]->ProfileX();
	}
	// Create a new canvas.
	TCanvas * c1 = new TCanvas("c1","Two HIstogram Fit example",100,10,900,800);
	c1->Divide(2,2);
	c1->cd(1);
	dE2E->Draw();
	TLegend*leg=new TLegend(0.4,0.6,0.89,0.89);
        for (int i=0;i<5;i++)
        {
                for(int j=1;j<2;j++)
                {
			tmp[i][j]->SetMarkerColor(i+j+1);
			tmp[i][j]->SetMarkerStyle(2);
                        tmp[i][j]->Draw("same");
			switch(i)
			{
			case 0:
				leg->AddEntry(tmp[i][j],"alpha","p");
				break;
			case 4:
                                leg->AddEntry(tmp[i][j],"3He","p");
                                break;
			case 3:
                                leg->AddEntry(tmp[i][j],"3H","p");
                                break;
			case 2:
                                leg->AddEntry(tmp[i][j],"2H","p");
                                break;
			case 1:
                                leg->AddEntry(tmp[i][j],"proton","p");
                                break;
			default:
				break;
			}
                }
        }
	leg->SetHeader("Illustration");
	leg->Draw("same");
	for( int i=0;i<3;i++)
	{
		c1->cd(i+2);
		p[i]->Draw();
	}
}
