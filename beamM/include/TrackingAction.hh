/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-29 14:40
* Filename: TrackingAction.hh
* Description: 
*************************************************/
#ifndef TrackingAction_h
#define TrackingAction_h 1

#include "G4UserTrackingAction.hh"
#include "RunAction.hh"
#include "DataBase.hh"
class TrackingAction : public G4UserTrackingAction 
{
public:
  TrackingAction(RunAction*);
  virtual ~TrackingAction(){};
   
  virtual void PreUserTrackingAction(const G4Track*);
  virtual void PostUserTrackingAction(const G4Track*);
  RunAction*aRun;
	DataBase*aData;
};

#endif
