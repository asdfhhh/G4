/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:02
* Filename:		DetSD.cc
* Description: 
*************************************************/

#include "DetSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4ParticleTypes.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetSD::DetSD(G4String name)
:G4VSensitiveDetector(name),HCID(-1)
{
	G4String HCname;
	collectionName.insert(HCname="DetCollection");

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetSD::~DetSD()
{
  
 }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetSD::Initialize(G4HCofThisEvent* HCE)
{
  DetCollection = new DetHitsCollection
                        (SensitiveDetectorName,collectionName[0]); 
	if(HCID<0)
 	{ HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); }
	HCE->AddHitsCollection( HCID, DetCollection );  

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool DetSD::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
	e = aStep->GetTotalEnergyDeposit();
	if(e==0.) return false;
	DetHit* newHit = new DetHit();
 	newHit->SetEdep(e);
	newHit->SetPos (aStep->GetPostStepPoint()->GetPosition());
	DetCollection->insert( newHit );
	return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetSD::EndOfEvent(G4HCofThisEvent*HCE)
{

} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

