/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-07-01 14:49
* Filename:		Target.hh
* Description: 
*************************************************/

#ifndef Target_H
#define Target_H 1
#include "globals.hh"
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
#include "G4VUserDetectorConstruction.hh"
#include "G4Tubs.hh"

class Target
{
  public:

	Target();
	~Target();
	G4LogicalVolume* Construct();
	int nTarget;
	//parameters
	G4double d1;
	G4double d2;
	G4double R;
	G4double Target_len;
 private:
	//tubs of Target
	G4Tubs *T1_tub;
	G4Tubs *T2_tub;
	G4Tubs *aTarget_tub;
	// Logical volumes
	G4LogicalVolume* T1_log;
	G4LogicalVolume* T2_log;
	G4LogicalVolume* aTarget_log;
	// Physical volumes
	G4VPhysicalVolume* T1_phys;
	G4VPhysicalVolume* T2_phys;
	G4VPhysicalVolume* aTarget_phys;
};

#endif

