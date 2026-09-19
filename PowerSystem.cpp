#include <iostream>
#include "PowerSystem.h"

using namespace std;

// Constructor
PowerSystem::PowerSystem(
    int id,
    string name,
    double power)
    : CityComponent(id, name)
{
    powerLevel = power;
}

// Destructor
PowerSystem::~PowerSystem()
{
    cout << "PowerSystem destroyed." << endl;
}

// Supplies power to the city.
void PowerSystem::supplyPower()
{
    cout << "PowerSystem is supplying power."
         << endl;

    cout << "Current power level: "
         << powerLevel << endl;
}

// Processes a power-related event.
void PowerSystem::processEvent()
{
    cout << "PowerSystem processing a power event."
         << endl;

    supplyPower();
}