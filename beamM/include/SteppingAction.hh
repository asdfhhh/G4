/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-08-10 11:04
* Filename: SteppingAction.hh
* Description: 
*************************************************/
#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "RunAction.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(RunAction*);
  virtual ~SteppingAction();

  void UserSteppingAction(const G4Step*);
    
private:
	RunAction *ThisRun;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
