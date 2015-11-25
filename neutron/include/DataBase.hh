/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-01 14:46
* Filename: DataBase.hh
* Description: 
*************************************************/
#ifndef DataBase_h
#define DataBase_h 1
#include "globals.hh"
#include "G4UnitsTable.hh"

#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TTree.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#ifndef Det_TEST

class DataBase
{
public:
	DataBase(int);
	~DataBase();
	int sample_event;
	int sub_event;
	void MakeTree(int);
	void FillTrueth(double,int);
	void FillData(int,int);
	void FillOnline(int); 
	void Fill2DOnline(int,int,int);
	void FillVertexEnergy(double) ;
	void SaveData(int);
	void SaveTrueth();
	void ResetOnline();
	inline void AddSampleEvent(){sample_event++;}
	inline void AddSubEvent(){sub_event++;}
	int GetSampleEvent(){return sample_event;}
	int GetSubEvent(){return sub_event;}

	TH1F*v_energy;

private: 
	TTree*t;
	TTree*d;
	char Hname[100];
	TFile* hfile;
	double *energy;
	int *D_energy;
	int Evn_number;
	ofstream bin_file;
};
#endif
#endif /*DataBase_h*/

