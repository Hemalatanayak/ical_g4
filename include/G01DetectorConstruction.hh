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
/// \file persistency/gdml/G01/include/G01DetectorConstruction.hh
/// \brief Definition of the G01DetectorConstruction class
//
//
//
//

#ifndef _G01DETECTORCONSTRUCTION_H_
#define _G01DETECTORCONSTRUCTION_H_

#include "G4VUserDetectorConstruction.hh"
#include "G4UniformMagField.hh"
#include "G4TransportationManager.hh"
#include "G4FieldManager.hh"
#include <G4SystemOfUnits.hh>

/// Detector construction allowing to use the geometry read from the GDML file

class G01DetectorConstruction : public G4VUserDetectorConstruction
{
public:

  G01DetectorConstruction(G4VPhysicalVolume *setWorld = 0)
  {   
    fWorld = setWorld;
    G4cout<<fWorld->GetName()<<G4endl;
    G4cout<<"Found "<<fWorld->GetLogicalVolume()->GetNoDaughters()<<" daughters in the mother volume ..."<<G4endl; 
    int nDaughters = fWorld->GetLogicalVolume()->GetNoDaughters();
    G4UniformMagField* magField = new G4UniformMagField(G4ThreeVector(0,1.5E4*gauss ,0));     //10.5E4*gauss   
    G4FieldManager* fieldMgr    = new G4FieldManager(magField);
    fieldMgr->SetDetectorField(magField);
    fieldMgr->CreateChordFinder(magField);

    for (int i=0; i<nDaughters;i++){
      // G4cout<<fWorld->GetLogicalVolume()->GetDaughter(i)->GetName()<<G4endl;
      if(fWorld->GetLogicalVolume()->GetDaughter(i)->GetName().contains("IRON")){
      G4cout<<"Setting magnetic field in "<< fWorld->GetLogicalVolume()->GetDaughter(i)->GetName() <<G4endl;
      fWorld->GetLogicalVolume()->GetDaughter(i)->GetLogicalVolume()->SetFieldManager(fieldMgr, true);

      }
    }
    
  }

  virtual G4VPhysicalVolume *Construct()
  {
    return fWorld;
  }

private:

  G4VPhysicalVolume *fWorld;
};

#endif
