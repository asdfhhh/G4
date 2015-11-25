/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:04
* Filename:		DetSD.hh
* Description: 
*************************************************/

#ifndef DetSD_h
#define DetSD_h 1

#include "G4VSensitiveDetector.hh"
#include "DetHit.hh"


class G4Step;
class G4HCofThisEvent;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetSD : public G4VSensitiveDetector
{
  public:
      DetSD(G4String);
     ~DetSD();

      void Initialize(G4HCofThisEvent*);
      G4bool ProcessHits(G4Step*, G4TouchableHistory*);
      void EndOfEvent(G4HCofThisEvent*);

       
     
     
  private:
      DetHitsCollection* DetCollection;
       G4double e;
       G4double ed;
       int HCID;


};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

