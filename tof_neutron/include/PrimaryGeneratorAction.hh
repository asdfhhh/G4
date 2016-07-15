/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2016-07-15 10:49
* Filename:		PrimaryGeneratorAction.hh
* Description: 
*************************************************/

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1
#include "globals.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
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
	PrimaryGeneratorAction();
	~PrimaryGeneratorAction();
	void GeneratePrimaries(G4Event* anEvent);
private:
	G4ParticleGun* particleGun;
	PrimaryGeneratorMessenger* fGunMessenger;     
	TH1F*Gen_list;
	void InitialGenList();
};
#endif


