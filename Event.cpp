#include "Event.h"

// Constructor
Event::Event(string type, string loc, int priorityLevel)
{
    eventType = type;
    location = loc;
    priority = priorityLevel;
}

// Returns the type of event
string Event::getEventType() const
{
    return eventType;
}

// Returns the location of the event
string Event::getLocation() const
{
    return location;
}

// Returns the event priority
int Event::getPriority() const
{
    return priority;
}