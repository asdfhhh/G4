/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-08-10 11:04
* Filename: DetDigitizer.hh
* Description: 
*************************************************/
#ifndef DetDigitizer_h
#define DetDigitizer_h 1

#include "G4VDigitizerModule.hh"
#include "DetDigi.hh"
#include "globals.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class DetDigitizer : public G4VDigitizerModule
{
public:
  
  DetDigitizer(G4String name);
  ~DetDigitizer();
  
  void Digitize();
  void SetThreshold(G4double val) { Energy_Threshold = val;}
  G4double  SignalProcess(G4double, G4double);
private:
  
  DetDigitsCollection*  DigitsCollection;
  G4double Energy_Threshold; // for TKR digi
  G4double TotalEnergy; // for CAL analysis
  G4double ACDThreshold; // for ACD analysis

};

#endif








