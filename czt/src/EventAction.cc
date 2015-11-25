/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:02
* Filename:		EventAction.cc
* Description: 
*************************************************/

#include "EventAction.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "DetDigi.hh"
#include "DetDigitizer.hh"
#include "Randomize.hh"
#include <iomanip>
#include "DataBase.hh"
#include "DetSD.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction(RunAction*rct)
{
	ThisRun=rct;
	id=-1;
	printModulo=10000;
	G4DigiManager * fDM = G4DigiManager::GetDMpointer();
	DetDigitizer * myDM = new DetDigitizer( "DetDigitizer" );
	fDM->AddNewModule(myDM);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{
 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* evt)
{  
  G4int evtNb = evt->GetEventID();
  if (evtNb%printModulo == 0) { 
    G4cout << "\n---> Begin of event: " << evtNb << G4endl;
    CLHEP::HepRandom::showEngineStatus();
}
 	G4SDManager * SDman = G4SDManager::GetSDMpointer(); 
 	if(id<0)
	{
		G4String colNam;
		id = SDman->GetCollectionID(colNam="DetCollection");
	}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* evt)
{
 	G4int evtNb = evt->GetEventID();
	G4int P_id=0;

	DataBase*newdata=ThisRun->GetDataBase();
	if(id<0) return;
	G4HCofThisEvent * HCE = evt->GetHCofThisEvent();
	DetHitsCollection* PHC = 0;
	G4DigiManager * fDM = G4DigiManager::GetDMpointer();
	if(HCE||PHC)
	{
		PHC= (DetHitsCollection*)(HCE->GetHC(id));
	} 
	if(PHC)
	{
		int n_hit = PHC->entries();
		G4double T_E=0;
		for(int i=0;i<n_hit;i++)
		{  
			T_E+=(*PHC)[i]->GetEdep();
		}
		newdata->FillTrueth(T_E/keV,0);
		newdata->SaveTrueth();
	}	
	DetDigitizer * myDM =
	(DetDigitizer*)fDM->FindDigitizerModule( "DetDigitizer" );
	myDM->Digitize();

	G4int myDigiCollID = fDM->GetDigiCollectionID("DigitsCollection");

	DetDigitsCollection * DC = (DetDigitsCollection*)fDM->GetDigiCollection( myDigiCollID );
	if(DC)
	{
		G4int n_digi =  DC->entries();
		int T_E=0;
		for (G4int i=0;i<n_digi;i++)
		{
			T_E+=(*DC)[i]->GetADC();		
		}
		newdata->FillData(T_E,0);
		newdata->SaveData();
	}
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
