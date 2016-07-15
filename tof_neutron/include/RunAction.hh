/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-01 14:48
* Filename: RunAction.hh
* Description: 
*************************************************/

#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "DataBase.hh"

#include "DetectorConstruction.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Run;

class RunAction : public G4UserRunAction
{
public:
	RunAction(DetectorConstruction*);
	virtual ~RunAction();

	void BeginOfRunAction(const G4Run*);
	void   EndOfRunAction(const G4Run*);
	DataBase*data;
	DataBase*GetDataBase(){return data;};
private:
	DetectorConstruction*ThisDet;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

