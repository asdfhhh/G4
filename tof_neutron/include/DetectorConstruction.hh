/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2016-07-15 10:29
* Filename:		DetectorConstruction.hh
* Description: 
*************************************************/
#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1
#include "globals.hh"
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
#include "G4VUserDetectorConstruction.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "Target.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    DetectorConstruction();
    ~DetectorConstruction();
	int N_det;
    G4VPhysicalVolume* Construct();
	inline int GetNCell(){return N_det;}
  private:
 
    // solid volumes
    //
	G4Box* experimentalHall_box;
	G4Tubs* chamber_tub;
	G4Tubs* chamberinner_tub;
	G4Tubs* tube_tub;
	G4Box* detector_box;
    // Logical volumes
    //
    G4LogicalVolume* experimentalHall_log;
    G4LogicalVolume* detector_log;
    G4LogicalVolume* target_log;
    G4LogicalVolume* chamber_log;
    G4LogicalVolume* chamberinner_log;
    G4LogicalVolume* tube_log;
	Target *atarget;
    // Physical volumes
    //
    G4VPhysicalVolume* experimentalHall_phys;
    G4VPhysicalVolume* detector_phys;
    G4VPhysicalVolume* target_phys;
    G4VPhysicalVolume* chamber_phys;
    G4VPhysicalVolume* chamberinner_phys;
};

#endif

