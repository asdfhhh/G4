/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-01 14:46
* Filename: PrimaryGeneratorMessenger.cc
* Description: 
*************************************************/

#include "PrimaryGeneratorMessenger.hh"
#include "G4UIdirectory.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADouble.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorMessenger::PrimaryGeneratorMessenger(
                                             PrimaryGeneratorAction* Gun)
:G4UImessenger(),Action(Gun),
 fGunDir(0), 
 fDefaultCmd(0),
 fRndmCmd(0)
{
  fGunDir = new G4UIdirectory("/Edit/gun/");
  fGunDir->SetGuidance("gun control");
 
  fDefaultCmd = new G4UIcmdWithAnInteger("/Edit/gun/setGunType",this);
  fDefaultCmd->SetGuidance("set the particle gun type ");
  fDefaultCmd->SetGuidance("1:neutron 0:secondary charged particle");
  fDefaultCmd->SetParameterName("type",true);
  fDefaultCmd->SetDefaultValue(0);
  fDefaultCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorMessenger::~PrimaryGeneratorMessenger()
{
  delete fDefaultCmd;
  delete fGunDir;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorMessenger::SetNewValue(G4UIcommand* command,
                                               G4String newValue)
{ 
  if (command == fDefaultCmd)
   {Action->SetGunType(fDefaultCmd->GetNewIntValue(newValue));}
 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

