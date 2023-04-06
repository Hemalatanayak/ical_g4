//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file SteppingAction.cc
/// \brief Implementation of the B1::SteppingAction class

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G01DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

// namespace B1
// {

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* eventAction)
: fEventAction(eventAction)
{

    analysisManager = G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{
  const G01DetectorConstruction* detConstruction= static_cast<const G01DetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

  // if (!fScoringVolume) {
  //   const G01DetectorConstruction* detConstruction
  //     = static_cast<const G01DetectorConstruction*>
  //       (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
  //   fScoringVolume = detConstruction->GetScoringVolume();
  // }

  // // get volume of the current step
  // G4LogicalVolume* volume= step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
  // G4cout<<"I am in: "<<volume->GetName()<<" at "<< step->GetPreStepPoint()->GetPosition().x()<< step->GetPreStepPoint()->GetPosition().y()<<step->GetPreStepPoint()->GetPosition().z()<<G4endl;
    // G01DetectorConstruction(G4VPhysicalVolume *setWorld = 0)
    
    // fWorld = setWorld;
    // G4cout<<fWorld->GetName()<<G4endl;
    // G4cout<<"Found "<<fWorld->GetLogicalVolume()->GetNoDaughters()<<" daughters in the mother volume ..."<<G4endl; 

  // int nDaughters = 21;
  // for (int i=0; i<nDaughters;i++){
     G4LogicalVolume* volume= step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    //  G4double edepStep = step->GetTotalEnergyDeposit();
    //  if(volume->GetDaughter(i)->GetName().contains("GLASS"))
     if(volume->GetName().contains("GLASS"))
     {
      if(step->GetTrack()->GetDefinition()->GetPDGEncoding()== -13){
    //     const G4VTouchable *touchable = step->GetPreStepPoint()->GetTouchable();
    //    G4cout<<"I am in: "<<volume->GetName()<<" at " <<"x="<< step->GetPreStepPoint()->GetPosition().x()<< "y="<<step->GetPreStepPoint()->GetPosition().y()<<"z="<<step->GetPreStepPoint()->GetPosition().z()<<
    //  " energy: "<<step->GetTotalEnergyDeposit()<<G4endl;

      analysisManager->FillNtupleDColumn(0, G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID());
      analysisManager->FillNtupleDColumn(1, step->GetPreStepPoint()->GetPosition().x());
      analysisManager->FillNtupleDColumn(2, step->GetPreStepPoint()->GetPosition().y());
      analysisManager->FillNtupleDColumn(3, step->GetPreStepPoint()->GetPosition().z());
      analysisManager->FillNtupleDColumn(4, step->GetTrack()->GetGlobalTime());
      analysisManager->FillNtupleDColumn(5, step->GetTrack()->GetMomentum().x());
      analysisManager->FillNtupleDColumn(6, step->GetTrack()->GetMomentum().y());
      analysisManager->FillNtupleDColumn(7, step->GetTrack()->GetMomentum().z());
      analysisManager->AddNtupleRow();


      }
  
      // G4cout<<fWorld->GetLogicalVolume()->GetDaughter(i)->GetName()<<G4endl;
      // if(fWorld->GetLogicalVolume()->GetDaughter(i)->GetName().contains("GLASS")){
      // G4cout<<"The hit points are "<< step->GetPreStepPoint()->GetPosition().x()<< step->GetPreStepPoint()->GetPosition().y()<<step->GetPreStepPoint()->GetPosition().z()<<G4endl;
      }
  
  }

  // if(volume== )

  // // check if we are in scoring volume
  // if (volume != fScoringVolume) return;

  // // collect energy deposited in this step
  // G4double edepStep = step->GetTotalEnergyDeposit();
  // fEventAction->AddEdep(edepStep);
// }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// }
