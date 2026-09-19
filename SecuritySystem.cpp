#include <iostream>
#include "SecuritySystem.h"

using namespace std;

SecuritySystem::SecuritySystem(
    int id,
    string name,
    int threat)
    : CityComponent(id, name)
{
    threatLevel = threat;
}

SecuritySystem::~SecuritySystem()
{
    cout << "SecuritySystem destroyed." << endl;
}

void SecuritySystem::monitorCity()
{
    cout << "SecuritySystem is monitoring the city."
         << endl;

    cout << "Current threat level: "
         << threatLevel << endl;
}

void SecuritySystem::processEvent()
{
    cout << "SecuritySystem processing a security event."
         << endl;

    monitorCity();
}