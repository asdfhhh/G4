/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-07-01 14:39
* Filename:		DataBase.cc
* Description: 
*************************************************/
#include "DataBase.hh"
#ifndef Det_TEST

DataBase::DataBase(int Tname):sample_event(0),sub_event(0)
{
	printf("Initial data storage......\n");
	char name[100];

	//char bin_name[100];

//root file output
	sprintf(name,"ana/Data_%d.root",Tname );
	//sprintf(bin_name,"Data_%d.bin",Tname );
	cout<<"the ROOT file: "<<name<<" constructed."<<endl;
	//cout<<"the binary file: "<<bin_name<<" constructed."<<endl;
//initial the file output
	hfile = new TFile(name,"RECREATE","ROOT file in Simulation");
	//bin_file.open(bin_name,ios_base::binary);
	v_energy=new TH1F("v_energy","the Vertex Energy",200,0,100000);
	printf(".......Initial complete!\n");
}

DataBase::~DataBase()
{
	hfile->cd();
	hfile->Write();
	//bin_file.close();
	delete energy;
	//delete D_energy;
}

void DataBase::MakeTree(int det_num)
{
	int ch_num=det_num*4;
	energy=new double[ch_num];
	//D_energy=new int[ch_num];
	char Bname[12];
	//construct the tree
	t=new TTree("truth","Truth");
	for (int i= 0; i< ch_num; i++)
	{
		sprintf(Hname,"t_Ch%d",i+1); 
		sprintf(Bname,"energy%d/D",i+1);
		t->Branch(Hname,&energy[i],Bname);
	}

	/*d=new TTree("data","Data");
	for (int i= 0; i< ch_num; i++)
	{
		sprintf(Hname,"d_Ch%d",i+1);
		sprintf(Bname,"D_energy%d/I",i+1);
		d->Branch(Hname,&D_energy[i],Bname);
	}*/
}

 void DataBase::FillTrueth(double energy1,int D_id1)
{
	energy[D_id1]=energy1;
}

 void DataBase::SaveTrueth()
{
	t->Fill();
}

 void DataBase::FillData(int energy1,int D_id1)
{
	D_energy[D_id1]=energy1;
}

 void DataBase::SaveData(int ID)
{
/*	unsigned int tmp_data=235;
	bin_file.write((char*)(&tmp_data),1);
	tmp_data=144;
	bin_file.write((char*)(&tmp_data),1);
	tmp_data=ID;
	bin_file.write((char*)(&tmp_data),1);
	tmp_data=0;
	bin_file.write((char*)(&tmp_data),1);
	tmp_data=8706;
	bin_file.write((char*)(&tmp_data),2);
	for(int iii=0;iii<det_num;iii++)
	{
		bin_file.write((char*)(&iii),1);
		tmp_data=int((D_energy[iii]>>8)&0xff);
		bin_file.write((char*)(&tmp_data),1);
		tmp_data=int(D_energy[iii]&0xff);
		bin_file.write((char*)(&tmp_data),1);		
	}
	tmp_data=0;
	bin_file.write((char*)(&tmp_data),2);
	tmp_data=52445;
	bin_file.write((char*)(&tmp_data),2);
	d->Fill();*/
}

void DataBase::Fill2DOnline(int energy1,int P_id1,int P_id2)
{
/*	thp->Lock();
	map_online->Fill(P_id1,P_id2,energy1);
	thp->UnLock();*/
}

void DataBase::ResetOnline()
{
/*	thp->Lock();
	map_online->Reset();
	thp->UnLock();*/
}

void DataBase::FillOnline(int energy1)
{
/*	thp->Lock();
	total->Fill(energy1);
	thp->UnLock();*/
}
void DataBase::FillVertexEnergy(double energy1)
{
	v_energy->Fill(energy1);
}
#endif

