/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-07-01 14:38
* Filename:		Cell.cc
* Description: 
*************************************************/
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4Box.hh"
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
#include "Cell.hh"
#include "DetSD.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

using namespace std;

Cell::Cell(int N_Det)
:  dE1_tub(0),dE2_tub(0),dE3_tub(0),E_tub(0),aCell_tub(0),
dE1_log(0),dE2_log(0),dE3_log(0),E_log(0),aCell_log(0),
dE1_phys(0),dE2_phys(0),dE3_phys(0),E_phys(0),aCell_phys(0)
{
	nCell= N_Det;
	d1=0.5*um;
	d2=40*mm;
	d3=300*um;
	d4=30*mm;
	l1=1*cm;
	l2=1*cm;
	R=2*cm;
	Det_len=d1+d2+d3+d4+l1+l2;
}

Cell::~Cell()
{ 
}

G4LogicalVolume* Cell::Construct()
{ 
//materials
  G4double a;  // atomic mass
  G4double z;  // atomic number
  G4double density;
  G4Material* Vacuum ;
  Vacuum=new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
                           kStateGas, 3.e-18*pascal, 2.73*kelvin);
  G4NistManager* man = G4NistManager::Instance();
  man->SetVerbose(0);
  G4Material* Si= man->FindOrBuildMaterial("G4_Si");
  G4Material* Al= man->FindOrBuildMaterial("G4_Al");
  G4Material* CsI=man->FindOrBuildMaterial("G4_CESIUM_IODIDE");
/*//construction FR4
  z      = 6.;
  a      = 12.011*g/mole;
  G4Element* elC = new G4Element("Element_Carbon",  "C", z, a);

  z      = 1.;
  a      = 1.00794*g/mole;
  G4Element* elH = new G4Element("Element_Hydrogen", "H", z, a);

  z      = 8.;
  a      = 16.00*g/mole;
  G4Element* elO = new G4Element( "Element_Oxygen", "O", z, a);

  z      = 14.;
  a      = 28.09*g/mole;
  G4Element* elSi  = new G4Element("Element_Silicon", "Si", z, a);

  density     = 1.70*g/cm3;
  G4int ncomponents = 4;
  G4int natoms;
  G4double fractionmass;
  G4Material* FR4 = new G4Material("FR4",density , ncomponents);
	      FR4 -> AddElement(elSi, natoms=1);
	      FR4 -> AddElement(elO , natoms=2);
	      FR4 -> AddElement(elC , natoms=3);
	      FR4 -> AddElement(elH , natoms=3);
*/
//construction G4_POLYETHYLENE
  G4Material* PE= man->FindOrBuildMaterial("G4_POLYETHYLENE");
  G4Material* MYLAR= man->FindOrBuildMaterial("G4_MYLAR");
//construction Ar low pressure
  z = 18.;
  a = 39.95*g/mole;
  density     = 0.00166201/10*g/cm3;//1E5Pa divided by a factor
  int ncomponents = 1;
  int natoms;
  G4Element* elAr = new G4Element("Element_Argon",  "Ar", z, a);
  G4Material* Ar = new G4Material("Ar",density , ncomponents);
  Ar->AddElement(elAr,natoms=1);
  //G4Material* Ar= man->FindOrBuildMaterial("G4_Ar");

//detector construction
	dE1_tub=new G4Tubs("dE1_tub",0,R,d1/2,0,2*pi);
	dE2_tub=new G4Tubs("dE2_tub",0,R,d2/2,0,2*pi);
        dE3_tub=new G4Tubs("dE3_tub",0,R,d3/2,0,2*pi);
	E_tub=new G4Tubs("E_tub",0,R,d4/2,0,2*pi);
	aCell_tub=new G4Tubs("E_tub",0,R,Det_len/2,0,2*pi);
 
	dE1_log=new G4LogicalVolume(dE1_tub,MYLAR,"dE1_log");
        dE2_log=new G4LogicalVolume(dE2_tub,Ar,"dE2_log");
	dE3_log=new G4LogicalVolume(dE3_tub,Si,"dE3_log");
	E_log=new G4LogicalVolume(E_tub,CsI,"E_log");
	aCell_log=new G4LogicalVolume(aCell_tub,Vacuum,"aCell_log");

	dE1_phys=new G4PVPlacement(0,G4ThreeVector(0,0,Det_len/2-d1/2),dE1_log,"dE1",aCell_log,false,0);
	dE2_phys=new G4PVPlacement(0,G4ThreeVector(0,0,Det_len/2-d1-d2/2),dE2_log,"dE2",aCell_log,false,1);
	dE3_phys=new G4PVPlacement(0,G4ThreeVector(0,0,Det_len/2-d1-d2-l1-d3/2),dE3_log,"dE3",aCell_log,false,2);
	E_phys=new G4PVPlacement(0,G4ThreeVector(0,0,Det_len/2-d1-d2-l1-d3-l2-d4/2),E_log,"E",aCell_log,false,3);

  
//set colour
	G4VisAttributes* VisAtt1= new G4VisAttributes(G4Colour(0.5,0.5,0.5));
	G4VisAttributes* VisAtt2= new G4VisAttributes(G4Colour(0.0,1.0,1.0));
	G4VisAttributes* VisAtt3= new G4VisAttributes(G4Colour(0.0,1.0,0.0));
	G4VisAttributes* VisAtt4= new G4VisAttributes(G4Colour(1.0,1.0,0.0));
	G4VisAttributes* VisAtt5= new G4VisAttributes(G4Colour(0.0,1.0,0.5));

	dE1_log->SetVisAttributes(VisAtt5);
	dE2_log->SetVisAttributes(VisAtt2);
        dE3_log->SetVisAttributes(VisAtt3);
	E_log->SetVisAttributes(VisAtt3);
	aCell_log->SetVisAttributes(VisAtt4);
	aCell_log->SetVisAttributes (G4VisAttributes::Invisible);

//set SD
	G4SDManager* SDman = G4SDManager::GetSDMpointer();
	G4String Dname = "/Tel";
	DetSD * TelSD = new DetSD(Dname,nCell);
	SDman->AddNewDetector(TelSD);
	dE1_log->SetSensitiveDetector(TelSD);
	dE2_log->SetSensitiveDetector(TelSD);
        dE3_log->SetSensitiveDetector(TelSD);
	E_log->SetSensitiveDetector(TelSD);

	return aCell_log;
}
