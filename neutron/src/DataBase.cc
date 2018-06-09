/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2016-03-25 10:48
* Filename:		DataBase.cc
* Description: 
*************************************************/
#include "DataBase.hh"
#include "Initial.hh"
#include <time.h>
DataBase::DataBase(int Tname):sample_event(0),sub_event(0)
{
	printf("Initial data storage......\n");
	char name[100];

	//char bin_name[100];

//root file output
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (name,100,"ana/%Y%m%d%H%M%S.root",timeinfo);
	//sprintf(name,"ana/Data_%d.root",Tname );
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
	if(energy)delete energy;
	if(incident_time)delete incident_time;
	//delete D_energy;
}

void DataBase::MakeTree(int det_num)
{
	int ch_num=det_num*4;
	energy=new double[ch_num];
	incident_time=new double[ch_num];
	//D_energy=new int[ch_num];
	char Bname[12];
	//construct the tree
	t=new TTree("truth","Truth");
	for (int i= 0; i< ch_num; i++)
	{
		sprintf(Hname,"e_Ch%d",i+1); 
		sprintf(Bname,"energy%d/D",i+1);
		t->Branch(Hname,&energy[i],Bname);
 
		sprintf(Hname,"t_Ch%d",i+1);
		sprintf(Bname,"incident_time%d/D",i+1);
                t->Branch(Hname,&incident_time[i],Bname);
	
		sprintf(Hname,"n_Ch%d",i+1);
                sprintf(Bname,"incident_name%d/C",i+1);
                t->Branch(Hname,&incident_name[i],Bname);
	}

	/*d=new TTree("data","Data");
	for (int i= 0; i< ch_num; i++)
	{
		sprintf(Hname,"d_Ch%d",i+1);
		sprintf(Bname,"D_energy%d/I",i+1);
		d->Branch(Hname,&D_energy[i],Bname);
	}*/
	if(Target_flag)
	{
		v=new TTree("vertex","Vertex");
		v->Branch("V_name",&v_name,"name/C");
		v->Branch("V_energy",&v_energy,"energy/D");
		v->Branch("V_time",&v_time,"time/D");
	}	
}

 void DataBase::FillTrueth(double energy1,double time1,G4String name1,int D_id1)
{
	energy[D_id1]=energy1;
	incident_time[D_id1]=time1;
	strcpy(&incident_name[D_id1][100],name1.c_str());
	//G4cout<<incident_name[D_id1]<<G4endl;
}

 void DataBase::SaveTrueth()
{
	t->Fill();
}

 void DataBase::FillData(int energy1,int D_id1)
{
//	D_energy[D_id1]=energy1;
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
void DataBase::FillVertexEnergy(G4String name1,double energy1,double time1)
{
//	v_name[strlen(name1.c_str())];
	strcpy(v_name,name1.c_str());
	v_time=time1;
	v_energy=energy1;
	v->Fill();
}

