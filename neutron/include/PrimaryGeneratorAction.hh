/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-12-24 14:46
* Filename:		PrimaryGeneratorAction.hh
* Description: 
*************************************************/

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1
#include "globals.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"
#include "TH1F.h"
#include "Initial.hh"

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
private:
	G4ParticleGun* particleGun;
	DetectorConstruction*thisdet;    
	PrimaryGeneratorMessenger* fGunMessenger;     
	#if Target_flag
	TH1F*Gen_list;
	void InitialGenList();
	#endif
};
#endif


