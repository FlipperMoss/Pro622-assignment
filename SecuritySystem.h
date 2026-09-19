#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "CityComponent.h"

class SecuritySystem : public CityComponent
{
private:
    // Current threat level.
    int threatLevel;

public:
    // Constructor
    SecuritySystem(
        int id,
        string name,
        int threat);

    // Destructor
    ~SecuritySystem();

    // Security-specific function
    void monitorCity();

    // Override processEvent()
    void processEvent() override;
};

#endif