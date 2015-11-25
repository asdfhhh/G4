/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-01 14:43
* Filename: DetHit.cc
* Description: 
*************************************************/
#include "DetHit.hh"
#include "G4ios.hh"
#include "G4VVisManager.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"

G4Allocator<DetHit> DetHitAllocator;

DetHit::DetHit()
{
}


DetHit::~DetHit()
{;}

DetHit::DetHit(const DetHit &right)
  : G4VHit()
{
  edep = right.edep;
}
const DetHit& DetHit::operator=(const DetHit &right)
{
  edep = right.edep;
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


