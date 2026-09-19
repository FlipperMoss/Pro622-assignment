#include <iostream>
#include "TransportSystem.h"

using namespace std;

// Constructor
TransportSystem::TransportSystem(
    int id,
    string name,
    int traffic)
    : CityComponent(id, name)
{
    trafficFlow = traffic;
}

// Destructor
TransportSystem::~TransportSystem()
{
    cout << "TransportSystem destroyed." << endl;
}

// Manages traffic in the city.
void TransportSystem::manageTraffic()
{
    cout << "TransportSystem is managing traffic."
         << endl;

    cout << "Current traffic flow: "
         << trafficFlow << endl;
}

// Processes a transport-related event.
void TransportSystem::processEvent()
{
    cout << "TransportSystem processing a traffic event."
         << endl;

    manageTraffic();
}