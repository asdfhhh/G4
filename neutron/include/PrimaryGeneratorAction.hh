/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-01 14:48
* Filename: PrimaryGeneratorAction.hh
* Description: 
*************************************************/

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1
#include "globals.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"

class G4VPrimaryGenerator;
class G4ParticleGun;
class G4GeneralParticleSource;
class G4Event;
class PrimaryGeneratorMessenger;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
	PrimaryGeneratorAction(DetectorConstruction*);
	~PrimaryGeneratorAction();
	void GeneratePrimaries(G4Event* anEvent);
	int Gun_type;
	virtual void SetGunType(int type_tmp){Gun_type=type_tmp;};
private:
	G4ParticleGun* particleGun;
	DetectorConstruction*thisdet;    
	PrimaryGeneratorMessenger* fGunMessenger;     
};
#endif


