#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

#include "CityComponent.h"

// DERIVED CLASS: HealthSystem

class HealthSystem : public CityComponent
{
private:
    int hospitalCnt;

public:
    // Constructor
    HealthSystem(
        int id,
        string name,
        int hospitals);

    // Destructor
    ~HealthSystem();

    void provideCare();
    void processEvent() override;
};

#endif