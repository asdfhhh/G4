/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:03
* Filename:		DetectorConstruction.cc
* Description: 
*************************************************/
#include "DetectorConstruction.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4EqMagElectricField.hh"
#include "G4UniformElectricField.hh"
#include "G4PVPlacement.hh"
#include "G4SubtractionSolid.hh"
#include "G4RotationMatrix.hh"
#include "globals.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4FieldManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4SDManager.hh"
#include "G4VisAttributes.hh"
#include "G4NistManager.hh"
#include "DetSD.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

using namespace std;

DetectorConstruction::DetectorConstruction()
 :  experimentalHall_log(0), detector_log(0),
    experimentalHall_phys(0),detector_phys(0)
{ 
}

DetectorConstruction::~DetectorConstruction()
{ 
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{ 
	printf("Initial Detector construction......");
	G4double a;  // atomic mass
	G4double z;  // atomic number
	G4double density;
	G4Material* Vacuum ;
	Vacuum=new G4Material("Galactic", z=1., a=1.01*g/mole,density=universe_mean_density,kStateGas, 3.e-18*pascal, 2.73*kelvin);
	G4NistManager* man = G4NistManager::Instance();
	man->SetVerbose(0);
	G4Material* czt= man->FindOrBuildMaterial("G4_CADMIUM_TELLURIDE");
	//------------------------------ experimental hall (world volume)
	//------------------------------ beam line along z axis
 
	experimentalHall_box = new G4Box("expHall_box",10*cm,10*cm,10*cm);
	experimentalHall_log = new G4LogicalVolume(experimentalHall_box,Vacuum,"expHall_log",0,0,0);
	experimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),experimentalHall_log,"expHall",0,false,0);
	//detector construction
	detector_box = new G4Box("detector_box",1*mm,1*mm,1.5*mm);
	detector_log = new G4LogicalVolume(detector_box,czt,"detector_log",0,0,0);
	detector_phys=new G4PVPlacement(0,G4ThreeVector(0,0,0),detector_log,"det",experimentalHall_log,false,0);
	experimentalHall_log->SetVisAttributes (G4VisAttributes::Invisible);
	//set SD
	G4SDManager* SDman = G4SDManager::GetSDMpointer();
	G4String Dname = "/Det";
	DetSD * detector_sd = new DetSD(Dname);
	SDman->AddNewDetector(detector_sd);
	detector_log->SetSensitiveDetector(detector_sd);
  	return experimentalHall_phys;
	printf("Initial complete!\n");
}


