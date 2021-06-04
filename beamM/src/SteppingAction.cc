/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-08-10 11:03
* Filename: SteppingAction.cc
* Description: 
*************************************************/
#include "SteppingAction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"
#include "DataBase.hh"
#include "G4StepPoint.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(RunAction*rct)                                  {
	ThisRun=rct;
 }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
	if(aStep->GetTrack()->GetParticleDefinition()->GetParticleName()!="e-")return;
	G4StepPoint*apoint=aStep->GetPostStepPoint();
        G4StepPoint*bpoint=aStep->GetPreStepPoint();
	if(apoint->GetPhysicalVolume()->GetName()!="expHall")return;
	if(bpoint->GetPhysicalVolume()->GetName()!="det")return;
	DataBase*newdata=ThisRun->GetDataBase();
	newdata->SaveVertex(apoint->GetKineticEnergy()/CLHEP::eV,apoint->GetPosition(),apoint->GetMomentumDirection());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
