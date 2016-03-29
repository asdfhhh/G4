/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2016-03-22 14:27
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
PrimaryGeneratorAction::PrimaryGeneratorAction(DetectorConstruction*det):thisdet(det)
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
	#if Target_flag
	InitialGenList();
	#endif

}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete particleGun;
  delete fGunMessenger;  
}
#if Target_flag
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
#endif
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	int evtNb=anEvent->GetEventID();
	G4double Det_R=thisdet->GetDetR();
	G4double Det_dis=thisdet->GetDetD();
	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName;
	G4ParticleDefinition* particle;	
	#if Target_flag
	particle = particleTable->FindParticle(particleName="neutron");
	particleGun->SetParticleDefinition(particle);
	particleGun->SetParticleEnergy(Gen_list->GetRandom()*keV);
	particleGun->SetParticleMomentumDirection(G4ThreeVector(0,-1,0)); 
	particleGun->SetParticlePosition(G4ThreeVector(0,55*m,0));
	particleGun->GeneratePrimaryVertex(anEvent);
	#else
		#if random_particle
	switch(evtNb%5)
		{
		case 1:
			particle = particleTable->FindParticle(particleName="proton");
			particleGun->SetParticleDefinition(particle);
			particleGun->SetParticleEnergy(200*G4UniformRand()*MeV);
			break;
	        case 2:
			particle = particleTable->FindParticle(particleName="deuteron");
	 	        particleGun->SetParticleDefinition(particle);
			particleGun->SetParticleEnergy(200*G4UniformRand()*MeV);
			break;
		case 3:
  	        	particle = particleTable->FindParticle(particleName="triton");
			particleGun->SetParticleDefinition(particle);
			particleGun->SetParticleEnergy(200*G4UniformRand()*MeV);
			break;
		case 4:
  	        	particle = particleTable->FindParticle(particleName="He3");
			particleGun->SetParticleDefinition(particle);
			particleGun->SetParticleEnergy(60*G4UniformRand()*MeV);
			break;
		case 0:
   	             	particle = particleTable->FindParticle(particleName="alpha");
   	             	particleGun->SetParticleDefinition(particle);
			particleGun->SetParticleEnergy(60*G4UniformRand()*MeV);
   	             	break;
   	    	default:
   	            	break;		
		}
		#else
		particleGun->SetParticleEnergy(200*G4UniformRand()*MeV);
		#endif
		#if gun_direction
		particleGun->SetParticleMomentumDirection(G4ThreeVector((2*G4UniformRand()-1),(2*G4UniformRand()-1),(2*G4UniformRand()-1))); 
		#else 
		particleGun->SetParticleMomentumDirection(G4ThreeVector(0,-1,0)); 
		#endif
	particleGun->SetParticlePosition(G4ThreeVector(0,0,0*cm));
	particleGun->GeneratePrimaryVertex(anEvent); 
	#endif
} 


