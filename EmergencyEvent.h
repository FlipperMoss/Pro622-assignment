#ifndef EMERGENCYEVENT_H
#define EMERGENCTEVENT_H

#include <iostream>
using namespace std;

// Emergencies that require immediate attention

class EmergencyEvent
{
private:
    string emergencyType;
    string location;

public:
    // constructor
    EmergencyEvent(string type, string loc);

    // Getters
    string getEmergencyType() const;
    string getLocation() const;
};

#endif