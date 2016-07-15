/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2016-03-27 16:39
* Filename:		DetHit.hh
* Description: 
*************************************************/

#ifndef DetHit_h
#define DetHit_h 1
#include "globals.hh"
#include "G4UnitsTable.hh"

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4String.hh"
class DetHit : public G4VHit
{
  public:

      DetHit();
      ~DetHit();
      DetHit(const DetHit &right);
      const DetHit& operator=(const DetHit &right);
      G4int operator==(const DetHit &right) const;

      inline void *operator new(size_t);
      inline void operator delete(void *aHit);

      void Draw();
      void Print();

  private:
	G4double edep;
	G4double intime;
	G4String inname;
  public:
	inline void SetEdep(G4double de)
	{ edep =de;}
	inline void AddEdep(G4double de)
        { edep +=de;}
        inline G4double GetEdep()
	{ return edep; }
	inline void SetInTime(G4double time_incident)
	{ intime=time_incident;}
	inline G4double GetInTime()
	{ return intime;}
	inline void SetTrackName(G4String name_incident)
	{ inname=name_incident;}
	inline G4String GetTrackName()
	{return inname;}

};

typedef G4THitsCollection<DetHit> DetHitsCollection;

extern G4Allocator<DetHit> DetHitAllocator;

inline void* DetHit::operator new(size_t)
{
  void *aHit;
  aHit = (void *) DetHitAllocator.MallocSingle();
  return aHit;
}

inline void DetHit::operator delete(void *aHit)
{
  DetHitAllocator.FreeSingle((DetHit*) aHit);
}

#endif


