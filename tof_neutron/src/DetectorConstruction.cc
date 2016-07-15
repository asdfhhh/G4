/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2016-07-15 10:59
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
#include "Initial.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "DetSD.hh"

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
	N_det=detector_n;
	G4double Det_dis=20*cm; 
	printf("Initial Detector construction......");
	G4double a;  // atomic mass
	G4double z;  // atomic number
	G4double density;
	G4Material* Vacuum ;
	Vacuum=new G4Material("Galactic", z=1., a=1.01*g/mole,density=universe_mean_density,kStateGas, 3.e-18*pascal, 2.73*kelvin);
	G4NistManager* man = G4NistManager::Instance();
	man->SetVerbose(0);
	G4Material* Fe= man->FindOrBuildMaterial("G4_Fe");
	G4Material* Si= man->FindOrBuildMaterial("G4_Si");
	//------------------------------ experimental hall (world volume)
	//------------------------------ beam line along z axis
 
	experimentalHall_box = new G4Box("expHall_box",2*m,60*m,2*m);
	experimentalHall_log = new G4LogicalVolume(experimentalHall_box,Vacuum,"expHall_log",0,0,0);
	experimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),experimentalHall_log,"expHall",0,false,0);
	//chamber construction
	chamber_tub=new G4Tubs("chamber_tub",0*cm,52*cm,12*cm,0,360*deg);
	chamberinner_tub=new G4Tubs("chamberinner_tub",0*cm,50*cm,10*cm,0,360*deg);
	tube_tub=new G4Tubs("tube_tub",5*cm,6*cm,30*cm,0,360*deg);
	chamber_log= new G4LogicalVolume(chamber_tub,Fe,"chamber_log",0,0,0);
	chamberinner_log= new G4LogicalVolume(chamber_tub,Vacuum,"chamberinner_log",0,0,0);
        tube_log= new G4LogicalVolume(tube_tub,Fe,"tube_log",0,0,0);
	G4RotationMatrix* rm_x = new G4RotationMatrix();
	rm_x->rotateX(90*deg);	
	chamberinner_phys=new G4PVPlacement(0,G4ThreeVector(0,0,0),chamberinner_log,"chamberinner_phys",chamber_log,false,0);
	chamberinner_phys=new G4PVPlacement(0,G4ThreeVector(0,0,0),chamber_log,"chamber_phys",experimentalHall_log,false,0);
        new G4PVPlacement(rm_x,G4ThreeVector(0,82*cm,0),tube_log,"tube1_phys",experimentalHall_log,false,0);
	new G4PVPlacement(rm_x,G4ThreeVector(0,-82*cm,0),tube_log,"tube2_phys",experimentalHall_log,false,1);
	//detector construction
	detector_box=new G4Box("detector_box",1*cm,1.25*cm,250*um);
	detector_log=new G4LogicalVolume(detector_box,Si,"detector_log",0,0,0);
	char name[10];
	double d_angle=180/N_det;
	for(int i=0;i<N_det;i++)
	{
		G4RotationMatrix* rm_d = new G4RotationMatrix();
		sprintf(name,"det_%d",i);
		G4double r_angle=0;
		if (i<(N_det/2))r_angle=(i+1)*d_angle*deg;
		else r_angle=(i-(N_det/2)+1)*d_angle*deg+180*deg;
		rm_d->rotateX(90*deg);
		rm_d->rotateY(r_angle);	
		new G4PVPlacement(rm_d,G4ThreeVector(sin(r_angle)*Det_dis,-cos(r_angle)*Det_dis,0),detector_log,name,chamberinner_log,false,i);
	}
	//construction the target
	G4RotationMatrix* rm_t= new G4RotationMatrix();
	rm_t->rotateX(90*deg);
	rm_t->rotateY(45*deg);
	atarget=new Target();
	target_log=atarget->Construct();
	target_phys=new G4PVPlacement(rm_t,G4ThreeVector(0,0,0),target_log,name,chamberinner_log,false,0);
	//give some colour see see
	G4VisAttributes* VisAtt1= new G4VisAttributes(G4Colour(0.5,0.5,0.5));
	chamber_log->SetVisAttributes(G4VisAttributes::Invisible);
	chamberinner_log->SetVisAttributes (G4VisAttributes::Invisible);
	experimentalHall_log->SetVisAttributes (G4VisAttributes::Invisible);
	//SD setting
        G4SDManager* SDman = G4SDManager::GetSDMpointer();
        G4String Dname = "/Det";
        DetSD * TelSD = new DetSD(Dname,N_det);
        SDman->AddNewDetector(TelSD);
        detector_log->SetSensitiveDetector(TelSD);

// print the table of materials
	G4cout << *(G4Material::GetMaterialTable()) << endl;	
	printf("Initial complete!\n");
	return experimentalHall_phys;
}


