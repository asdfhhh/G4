/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-29 14:41
* Filename: TrackingAction.cc
* Description: 
*************************************************/
#include "TrackingAction.hh"
#include "G4TrackingManager.hh"
#include "G4Track.hh"
#include "G4RunManager.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 
TrackingAction::TrackingAction(RunAction*rct)
:G4UserTrackingAction()
{
	aRun=rct;
}

void TrackingAction::PreUserTrackingAction(const G4Track* aTrack)
{
  // find the secondary particle emitt from sample or substain
/*const G4ThreeVector& GetVertexPosition() const GetTrack->GetVertexPosition()
const G4ThreeVector& GetVertexMomentumDirection() const
G4double GetVertexKineticEnergy()
G4ParticleDefinition* GetDefinition( ) const
const G4LogicalVolume * GetLogicalVolumeAtVertex () const G4String GetName () const
*/  
	aData=aRun->GetDataBase();
	G4String Log_name;
	if(aTrack->GetParentID()!=0)
	{
		Log_name=aTrack->GetLogicalVolumeAtVertex()->GetName();
		if (Log_name=="T1_log")
		{
			aData->AddSampleEvent();
			aData->FillVertexEnergy((aTrack->GetVertexKineticEnergy())/keV);
		}
		else if (Log_name=="T2_log")aData->AddSubEvent();
	}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 
void TrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
;
}


