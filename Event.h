#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event
{
private:
    string eventType;
    string location;
    int priority;

public:
    // constructor
    Event(string type, string loc, int priorityLevel);

    // Getters
    string getEventType() const;
    string getLocation() const;
    int getPriority() const;
};

#endif