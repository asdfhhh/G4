/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-08-10 11:01
* Filename: DetDigi.cc
* Description: 
*************************************************/
#include "DetDigi.hh"
#include "G4SystemOfUnits.hh"
G4Allocator<DetDigi> DetDigiAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

DetDigi::DetDigi():CpNo(0),ADC(0),slope(1*keV),pedal(0)
{
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

DetDigi::~DetDigi()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

DetDigi::DetDigi(const DetDigi& right)
  :G4VDigi()
{
  ADC= right.ADC;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

const DetDigi& DetDigi::operator=(const DetDigi& right)
{
  ADC= right.ADC;
  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

int DetDigi::operator==(const DetDigi& right) const
{ 
 return (this==&right) ? 1 : 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void DetDigi::Draw()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void DetDigi::Print()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....











