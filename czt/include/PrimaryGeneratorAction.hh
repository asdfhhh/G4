/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:03
* Filename:		PrimaryGeneratorAction.hh
* Description: 
*************************************************/

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1
#include "globals.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

class G4VPrimaryGenerator;
class G4ParticleGun;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();
    void GeneratePrimaries(G4Event* anEvent);

  private:

   G4ParticleGun* particleGun;

   };

#endif


