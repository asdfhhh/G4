/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-11-27 11:24
* Filename:		Cell.hh
* Description: 
*************************************************/

#ifndef Cell_H
#define Cell_H 1
#include "globals.hh"
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
#include "G4VUserDetectorConstruction.hh"
#include "G4Box.hh"
/*/////////////////////////////////////////////////////////

      dE1 dE2       dE3                 E
     ========      =====          ==================  
    |    |   |    |     |        |                  | 
    | w  |   |    |     |        |                  | 
    | i  |   |    |     |        |                  | 
    | n  |   |    |     |        |                  | 
    | d  |Gas|R1  |  Si |R2      |     CsI(Tl)      |R3
    | o  |   |    |     |        |                  |
    | w  |   |    |     |        |                  |
    |    |   |    |     |        |                  |
    |    |   |    |     |        |                  |
     ========      =====          ==================
    <-d1-><d2><l1><-d3 -><--l2--><-------d4--------->


*///////////////////////////////////////////////////////////
class Cell
{
  public:

	Cell(int );
	~Cell();
	G4LogicalVolume* Construct();
	int nCell;
	//parameters
	G4double d1;
	G4double d2;
	G4double d3;
        G4double d4;
	G4double l1;
	G4double l2;
	G4double R1;
	G4double R2;
        G4double R3;
	G4double R;
	G4double Det_len;
	inline G4double GetRadius(){return R;}
        inline G4double GetHalfLength(){return Det_len/2;}
 private:
	//boxes of 3 detectors
	G4Box *dE1_box;
	G4Box *dE2_box;
        G4Box *dE3_box;
	G4Box *E_box;
	G4Box *aCell_box;
	// Logical volumes
	G4LogicalVolume* dE1_log;
	G4LogicalVolume* dE2_log;
        G4LogicalVolume* dE3_log;
	G4LogicalVolume* E_log;
	G4LogicalVolume* aCell_log;
	// Physical volumes
	G4VPhysicalVolume* dE1_phys;
	G4VPhysicalVolume* dE2_phys;
        G4VPhysicalVolume* dE3_phys;
	G4VPhysicalVolume* E_phys;
	G4VPhysicalVolume* aCell_phys;
};

#endif

