/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:01
* Filename:		DetHit.cc
* Description: 
*************************************************/
#include "DetHit.hh"
#include "G4ios.hh"
#include "G4VVisManager.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"

G4Allocator<DetHit> DetHitAllocator;

DetHit::DetHit():edep(0),fPos(G4ThreeVector())
{
	
}


DetHit::~DetHit()
{;}

DetHit::DetHit(const DetHit &right)
  : G4VHit()
{
  edep = right.edep;
  fPos = right.fPos;
}
const DetHit& DetHit::operator=(const DetHit &right)
{
  edep = right.edep;
  fPos = right.fPos;
  return *this;
}

G4int DetHit::operator==(const DetHit &right) const
{
  return (this==&right) ? 1 : 0;
}

void DetHit::Draw()
{;}

void DetHit::Print()
{;}


