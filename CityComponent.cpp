#include <iostream>
#include "cityComponent.h"

using namespace std;

// Constructor
CityComponent::CityComponent(int id, string componentName)
{
    componentID = id;
    name = componentName;
    active = false;

    cout << "CityComponent created: "
         << name << endl;
}

// Virtual destructor
CityComponent::~CityComponent()
{
    cout << "CityComponent destroyed: "
         << name << endl;
}

// Activates the component.
void CityComponent::activate()
{
    active = true;

    cout << name
         << " has been activated." << endl;
}

// Deactivates the component.
void CityComponent::deactivate()
{
    active = false;

    cout << name
         << " has been deactivated." << endl;
}

// Returns the current status.
string CityComponent::getStatus() const
{
    if (active)
    {
        return "Active";
    }

    return "Inactive";
}