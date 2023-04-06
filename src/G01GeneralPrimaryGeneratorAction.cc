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
/// \file persistency/gdml/G01/src/G01PrimaryGeneratorAction.cc
/// \brief Implementation of the G01PrimaryGeneratorAction class
//
//
//
//

#include "G01GeneralPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include"G4UniformMagField.hh"
#include"G4FieldManager.hh"
#include"G4TransportationManager.hh"
#include"Randomize.hh"
#include"G4RandomDirection.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G01GeneralPrimaryGeneratorAction::G01GeneralPrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction(),
   fParticleGun(0)
{
  // G4int n_particle = 1;
  // // fParticleGun = new G4ParticleGun(n_particle);
  fParticleGun = new  G4GeneralParticleSource();

  // G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  // G4String particleName;
  // fParticleGun->SetParticleDefinition(particleTable->FindParticle(particleName="mu+"));
  // fParticleGun->SetParticleEnergy(1*GeV);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G01GeneralPrimaryGeneratorAction::~G01GeneralPrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void G01GeneralPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{

  // G4double xPos=(G4UniformRand()-0.5)*16*m;
  // G4double yPos=(G4UniformRand()-0.5)*16*m;
  // G4double zPos=(G4UniformRand()-0.5)*14.5*m;

  // fParticleGun->SetParticlePosition(G4ThreeVector(xPos,yPos,zPos));
  // G4ThreeVector momentumUnitVector = G4RandomDirection();

 
  // fParticleGun->SetParticleMomentumDirection(momentumUnitVector);
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

