/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2016-07-15 10:49
* Filename:		PrimaryGeneratorAction.cc
* Description: 
*************************************************/

#include "PrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "Randomize.hh"
#include "G4GeneralParticleSource.hh"
#include "PrimaryGeneratorMessenger.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include <fstream>
using namespace std;
PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	G4int n_particle = 1;
	G4ParticleGun* fParticleGun = new G4ParticleGun(n_particle);
	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName;
	G4ParticleDefinition* particle;
	particle = particleTable->FindParticle(particleName="neutron");
	particleGun = fParticleGun;
	particleGun->SetParticleDefinition(particle);
	particleGun->SetParticleEnergy(1*MeV);
	particleGun->SetParticleMomentumDirection(G4ThreeVector(0,-1,0)); 
	particleGun->SetParticlePosition(G4ThreeVector(0,0,0*cm));
	//create a messenger for this class
	fGunMessenger = new PrimaryGeneratorMessenger(this);  
	InitialGenList();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete particleGun;
  delete fGunMessenger;  
}
void PrimaryGeneratorAction::InitialGenList()
{
	//create the neutron list histogram
	Gen_list = new TH1F("nlist", "the neutron spectrum in keV", 200, 0, 450000);
	ifstream file_in("n_list.txt");
	float energy;
	double number;
	while (!file_in.eof())
	{
		file_in >> energy;
		file_in >> number;
		Gen_list->Fill(energy, number);
	}
	file_in.close();
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	int evtNb=anEvent->GetEventID();
	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName;
	G4ParticleDefinition* particle;	
	particle = particleTable->FindParticle(particleName="neutron");
	particleGun->SetParticleDefinition(particle);
	particleGun->SetParticleEnergy(Gen_list->GetRandom()*keV);
	particleGun->SetParticleMomentumDirection(G4ThreeVector(0,-1,0)); 
	particleGun->SetParticlePosition(G4ThreeVector(0,55*m,0));
	particleGun->GeneratePrimaryVertex(anEvent);
} 


