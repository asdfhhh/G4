/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:01
* Filename:		DataBase.cc
* Description: 
*************************************************/
#include "DataBase.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#ifndef Det_TEST

DataBase::DataBase(int Tname)
{
	printf("Initial data storage......\n");
	char name[100];

	//char bin_name[100];

//root file output
	sprintf(name,"Data_%d.root",Tname );
	//sprintf(bin_name,"Data_%d.bin",Tname );
	cout<<"the ROOT file: "<<name<<" constructed."<<endl;
	//cout<<"the binary file: "<<bin_name<<" constructed."<<endl;
//initial the file output
	hfile = new TFile(name,"RECREATE","ROOT file in Simulation");
	//bin_file.open(bin_name,ios_base::binary);

	printf(".......Initial complete!\n");
}

DataBase::~DataBase()
{
	hfile->cd();
	hfile->Write();
	//bin_file.close();
	delete energy;
}

void DataBase::MakeTree(int det_num)
{
	int ch_num=det_num;
	energy=new double[ch_num];
	char Bname[12];
	//construct the tree
	t=new TTree("truth","Truth");
	for (int i= 0; i< ch_num; i++)
	{
		sprintf(Hname,"t_Ch%d",i+1); 
		sprintf(Bname,"energy%d/D",i+1);
		t->Branch(Hname,&energy[i],Bname);
	}

	v=new TTree("vertex","Vertex");
        v->Branch("V_pos",&v_pos,"x:y:z");
        v->Branch("V_energy",&v_energy,"energy/D");
        v->Branch("V_mon",&v_mon,"x:y:z");
}

 void DataBase::FillTrueth(double energy1,int D_id1)
{
	energy[D_id1]=energy1;
}

 void DataBase::SaveTrueth()
{
	t->Fill();
}

void DataBase::SaveVertex(double energy1,G4ThreeVector pos1,G4ThreeVector mon1)
{
        v_energy=energy1;
	v_pos.x=pos1.x()/mm;
        v_pos.y=pos1.y()/mm;
        v_pos.z=pos1.z()/mm;
	v_mon.x=mon1.x();
        v_mon.y=mon1.y();
        v_mon.z=mon1.z();
        v->Fill();
}

#endif

