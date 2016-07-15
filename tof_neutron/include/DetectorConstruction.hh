/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-07-01 14:46
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
#include "Cell.hh"
#include "Target.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    DetectorConstruction();
    ~DetectorConstruction();
	int N_det;
    G4VPhysicalVolume* Construct();
	G4double Det_R;
	G4double Det_dis;
	G4double Surf_dis;
	inline int GetNCell(){return N_det;}
	inline G4double GetDetR(){return Det_R;}
	inline G4double GetDetD(){return Surf_dis;}
  private:
 
    // solid volumes
    //
    G4Box* experimentalHall_box;
	G4Tubs* chamber_tub;
	G4Tubs* chamberinner_tub;
	G4Tubs* tube_tub;
    // Logical volumes
    //
    G4LogicalVolume* experimentalHall_log;
    G4LogicalVolume* detector_log;
    G4LogicalVolume* target_log;
    G4LogicalVolume* chamber_log;
    G4LogicalVolume* chamberinner_log;
    G4LogicalVolume* tube_log;
    Cell *acell;
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

