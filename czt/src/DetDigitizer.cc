/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-08-10 11:02
* Filename: DetDigitizer.cc
* Description: 
*************************************************/
#include "DetDigitizer.hh"
#include "DetDigi.hh"

#include "DetHit.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4ios.hh"
//#include "G4CollectionNameVector.hh"
#include <vector>
#include "G4SystemOfUnits.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

DetDigitizer::DetDigitizer(G4String name)
  :G4VDigitizerModule(name)
{
	G4String colName = "DigitsCollection";
	collectionName.push_back(colName);
	Energy_Threshold = 0.*keV;
	TotalEnergy = 0.;
	ACDThreshold = 15*keV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

DetDigitizer::~DetDigitizer()
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void DetDigitizer::Digitize()
{
	DigitsCollection = new DetDigitsCollection
	("DetDigitizer","DigitsCollection"); // to create the Digi Collection
  
	G4DigiManager* DigiMan = G4DigiManager::GetDMpointer();
  
	G4int THCID; // HitCollection
	G4ThreeVector pos;
	TotalEnergy = 0.; // at each event

// silicon Hits collection
  
	THCID = DigiMan->GetHitsCollectionID("DetCollection");  
	DetHitsCollection* THC = 0; 
	THC = (DetHitsCollection*)(DigiMan->GetHitsCollection(THCID));

	if (THC)
	{
		G4int n_hit = THC->entries();
		G4double Etotal=0;
		G4int NDet=0;
		for (G4int i=0;i<n_hit;i++)
		{
			Etotal = (*THC)[i]->GetEdep();
			pos=(*THC)[i]->GetPos();
			DetDigi* Digi = new DetDigi();
			G4cout<<pos.z()<<G4endl;
			Etotal = SignalProcess(Etotal,pos.z());
			Digi->SetADC(Etotal);
			DigitsCollection->insert(Digi);
		}
	}
 	StoreDigiCollection(DigitsCollection);
	G4int DCID = -1;
	if(DCID<0)
	{ 
		//DigiMan->List();
		DCID = DigiMan->GetDigiCollectionID("DetDigitizer/DigitsCollection");
	}
}
G4double DetDigitizer::SignalProcess(G4double TmpE,G4double z)
{
	G4double E = TmpE;
	G4double Fano=0.089;
	//make the energy radom
        E = G4RandGauss::shoot(E/keV,sqrt(E*Fano/keV)/(E/keV))*keV;
        //make the position dependen
        //electrons and holes drift time wiht mobility 1000/50 cm2/Vs;voltage 300V; 0.3cm thickness
        G4double t_e=(0.15+z/cm)/(1000*300/0.3);
	G4double t_h=(0.15-z/cm)/(50*300/0.3);
	//charge induced by electrons and holes with lifetime 3E-6s and 1E-6s
	G4double E_e=E*3E-6*(1000*300/0.3)*(1-exp(-t_e/3E-6))/0.3;
	G4double E_h=E*1E-6*(50*300/0.3)*(1-exp(-t_h/1E-6))/0.3;
	//get total
        E = E_e+E_h;
	return E;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










