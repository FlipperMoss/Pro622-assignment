#ifndef POWERSYSTEM_H
#define POWERSYSTEM_H

#include "CityComponent.h"

// DERIVED CLASS: PowerSystem

// Inherits from CityComponent.
//
// Additional attribute:
// powerLevel
//
// Additional function:
// supplyPower()

class PowerSystem : public CityComponent
{
private:
    // Stores the current power level.
    double powerLevel;

public:
    // Constructor
    PowerSystem(
        int id,
        string name,
        double power);

    // Destructor
    ~PowerSystem();

    // Power-specific function
    void supplyPower();

    // Override the virtual function from CityComponent.
    void processEvent() override;
};

#endif