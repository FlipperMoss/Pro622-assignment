#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include "CityComponent.h"

// DERIVED CLASS: TransportSystem

class TransportSystem : public CityComponent
{
private:
    // Stores the current traffic flow.
    int trafficFlow;

public:
    // Constructor
    TransportSystem(
        int id,
        string name,
        int traffic);

    // Destructor
    ~TransportSystem();

    // Transport-specific function
    void manageTraffic();

    // Override processEvent()
    void processEvent() override;
};

#endif