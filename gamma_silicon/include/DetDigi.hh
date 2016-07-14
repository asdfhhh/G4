/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-08-10 11:04
* Filename: DetDigi.hh
* Description: 
*************************************************/
#ifndef DetDigi_h
#define DetDigi_h 1

#include "G4VDigi.hh"
#include "G4TDigiCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class DetDigi : public G4VDigi
{

public:
  
  DetDigi();
  ~DetDigi();
  DetDigi(const DetDigi&);
  const DetDigi& operator=(const DetDigi&);
  int operator==(const DetDigi&) const;
  
  inline void* operator new(size_t);
  inline void  operator delete(void*);
  
  void Draw();
  void Print();

private:
  G4int CpNo;   //  the det copyno
  int ADC; // ADC 
  G4double slope;//unit=(channel/energy)
  G4double pedal;
public:
  
  //inline void SetCpNo(G4int num)   {CpNo = num;};
  inline void SetADC(G4double Ene)  {ADC =Ene/slope+pedal;};
  //inline G4int GetCh() {return CpNo;};
  inline int GetADC()  {return ADC;};
  

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

typedef G4TDigiCollection<DetDigi> DetDigitsCollection;

extern G4Allocator<DetDigi> DetDigiAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void* DetDigi::operator new(size_t)
{
  void* aDigi;
  aDigi = (void*) DetDigiAllocator.MallocSingle();
  return aDigi;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void DetDigi::operator delete(void* aDigi)
{
  DetDigiAllocator.FreeSingle((DetDigi*) aDigi);
}

#endif









