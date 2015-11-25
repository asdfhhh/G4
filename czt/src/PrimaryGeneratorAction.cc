/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:01
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
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
PrimaryGeneratorAction::PrimaryGeneratorAction()
{
  G4int n_particle = 1;
  G4ParticleGun* fParticleGun = new G4ParticleGun(n_particle);
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="gamma");
  fParticleGun->SetParticleDefinition(particle);
   
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.));
  fParticleGun->SetParticleEnergy(662*keV);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,-1)); 
  fParticleGun->SetParticlePosition(G4ThreeVector(0,0,1*cm));
  particleGun = fParticleGun;
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{	
	int evtNb=anEvent->GetEventID();
	particleGun->GeneratePrimaryVertex(anEvent);   
} 


