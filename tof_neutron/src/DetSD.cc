/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2016-07-15 10:44
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

DetSD::DetSD(G4String name,G4int nCells)
:G4VSensitiveDetector(name),HCID(-1)
{
	numberOfCells=nCells;
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
       for(G4int j=0;j<numberOfCells;j++)
  {
     DetHit* newHit = new DetHit();
 	 newHit->SetEdep(0);
  	 DetCollection->insert( newHit );
    }
  
	hit_flag=new int[numberOfCells];
	for(int i=0;i<numberOfCells;i++)hit_flag[i]=0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool DetSD::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
  e = aStep->GetTotalEnergyDeposit();
  if(e==0.) return false;

  G4int copyID =aStep->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber()+4*(aStep->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber(1));
 if((!hit_flag[copyID])&&(aStep->GetTrack()->GetParentID()==1))
	{
		(*DetCollection)[copyID]->SetInTime(aStep->GetPreStepPoint()->GetGlobalTime());
		(*DetCollection)[copyID]->SetTrackName(aStep->GetTrack()->GetParticleDefinition()->GetParticleName());
		hit_flag[copyID]=1;
	}
 (*DetCollection)[copyID]->AddEdep(e);

  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetSD::EndOfEvent(G4HCofThisEvent*HCE)
{

} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

