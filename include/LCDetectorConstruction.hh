// LCDetectorConstruction.hh
// LumiCal
//
//  Created on: Mar 2, 2009
//      Author: aguilar


#ifndef LCDETECTORCONSTRUCTION_HH_
#define LCDETECTORCONSTRUCTION_HH_ 1

#include "LCSensitiveDetector.hh"
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4NistManager.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

class LCDetectorConstruction : public G4VUserDetectorConstruction{
    public:
        LCDetectorConstruction();
        ~LCDetectorConstruction();

        G4NistManager *materials = G4NistManager::Instance();

        G4VPhysicalVolume *Construct();
        G4LogicalVolume *buildWorld();
        G4LogicalVolume *buildSlot();
        G4LogicalVolume *buildSensor();
        G4LogicalVolume *buildAbsorber();
        G4LogicalVolume *buildFanout(G4double zEpoxy, G4double zKapton, G4double zCu);
        G4LogicalVolume *buildAl();
        G4LogicalVolume *buildSi();
        void fancyVisualization();

    private:
        G4VPhysicalVolume *physicWorld;
        G4LogicalVolume *logicWorld;
        G4LogicalVolume *logicSlot;
        G4LogicalVolume *logicSensor;
        G4LogicalVolume *logicAbsorber;
        G4LogicalVolume *logicFanoutFront;
        G4LogicalVolume *logicFanoutBack;
        G4LogicalVolume *logicSi;
        G4LogicalVolume *logicAl;

        G4double zSlot = 4.5*mm;
        G4double zSensor = 0.79*mm;
        G4double zAbsorber = 3.5*mm;

        G4double zFanout = 0.15*mm;
        G4double zAl = 0.02*mm;
        G4double zSi = 0.32*mm;

        G4double rSensorMin = 80.*mm;
        G4double rSensorMax = 195.2*mm;
        G4double rSensorGap = 0.*mm; // default 1.2mm I dont know which to choose :c

        // Implement a sensitive detector object
        LCSensitiveDetector *SensDet;
};

#endif