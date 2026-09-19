#include "EmergencyEvent.h"

// Constructor
EmergencyEvent::EmergencyEvent(string type, string loc)
{
    emergencyType = type;
    location = loc;
}

string EmergencyEvent::getEmergencyType() const
{
    return emergencyType;
}

string EmergencyEvent::getLocation() const
{
    return location;
}