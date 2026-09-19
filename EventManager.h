#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <queue>
#include <stack>
#include <vector>
#include "Event.h"
#include "EmergencyEvent.h"

using namespace std;

class EventManager
{
private:
    // Queue follows FIFO: First event added = first event processed

    queue<Event> eventQueue;

    // Stack follows LIFO: Most recent emergency = first emergency processed

    stack<EmergencyEvent> emergencyStack;

    // Vector keeps a record of the processed events
    vector<Event> processedEvents;

public:
    void addEvent(const Event &event);
    void processNextEvent();
    void addEmergency(const EmergencyEvent &emergency);
    void processEmergency();
    void displayEvents() const;
    void displayEmergencies() const;

    int countHighPriorityEvents() const;
};

#endif