#include <iostream>
#include "HealthSystem.h"

using namespace std;

// Constructor
HealthSystem::HealthSystem(
    int id,
    string name,
    int hospitals)
    : CityComponent(id, name)
{
    hospitalCnt = hospitals;
}

// Destructor
HealthSystem::~HealthSystem()
{
    cout << "HealthSystem destroyed." << endl;
}

// Provides healthcare services.
void HealthSystem::provideCare()
{
    cout << "HealthSystem is providing care."
         << endl;

    cout << "Hospitals available: "
         << hospitalCnt << endl;
}

// Processes a health-related event.
void HealthSystem::processEvent()
{
    cout << "HealthSystem processing a health event."
         << endl;

    provideCare();
}