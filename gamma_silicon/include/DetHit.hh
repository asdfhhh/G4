/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-08-10 11:03
* Filename:		DetHit.hh
* Description: 
*************************************************/

#ifndef DetHit_h
#define DetHit_h 1

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
	G4ThreeVector fPos;
  public:
	inline void SetEdep(G4double de)
	{ edep =de;}
	inline void AddEdep(G4double de)
        { edep +=de;}
        inline G4double GetEdep()
	{ return edep; }
	inline	void SetPos(G4ThreeVector xyz)
	{ fPos = xyz; };
	inline	G4ThreeVector GetPos() const 
	{ return fPos; };
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


