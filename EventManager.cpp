#include <iostream>
#include <algorithm>
#include "EventManager.h"

using namespace std;

// Normal Event Queue

void EventManager::addEvent(const Event &event)
{
    eventQueue.push(event);
    cout << "Event added to queue: " << event.getEventType() << endl;
}

// porcesses the first event in the queue
void EventManager::processNextEvent()
{
    if (eventQueue.empty())
    {
        cout << "No events waiting in the queue." << endl;
        return;
    }

    // The front event is processed first because the queue follows FIFO ordering/
    Event currentEvent = eventQueue.front();

    cout << "\nProcessing event: " << currentEvent.getEventType() << endl;
    cout << "Location: " << currentEvent.getLocation() << endl;
    cout << "Priority: " << currentEvent.getPriority() << endl;

    // Store the processed event for later reporting
    processedEvents.push_back(currentEvent);

    // Remove the processed event from the queue
    eventQueue.pop();
}

// EMERGENCY STACK

// Adds an emergency to the stack
void EventManager::addEmergency(const EmergencyEvent &emergency)
{
    emergencyStack.push(emergency);

    cout << "Emergency added: " << emergency.getEmergencyType() << endl;
}

// Process the most recent emergency
void EventManager::processEmergency()
{
    if (emergencyStack.empty())
    {
        cout << "No emergency overrides avaialable" << endl;
        return;
    }

    // The top emergency is processed first because the stack follows LIFO ordering
    EmergencyEvent emergency = emergencyStack.top();

    cout << "\nProcessing emergency: " << emergency.getEmergencyType() << endl;
    cout << "Location: " << emergency.getLocation() << endl;

    // Remove the emergency from the stack
    emergencyStack.pop();
}

// DISPLAY FUNCTIONS

// displays the events currently waiting in the queue
void EventManager::displayEvents() const
{
    cout << "\n--- Events waiting in Queue ---" << endl;

    if (eventQueue.empty())
    {
        cout << "No events waiting." << endl;
        return;
    }

    // A copy is used because displaying the queue should not destroy the original queue
    queue<Event> tempQueue = eventQueue;

    while (!tempQueue.empty())
    {
        Event current = tempQueue.front();

        cout << "Event: "
             << current.getEventType()
             << " | Location: "
             << current.getLocation()
             << " | Priority: "
             << current.getPriority()
             << endl;

        tempQueue.pop();
    }
}

// Displays emergencies curretly in the stack
void EventManager::displayEmergencies() const
{
    cout << "\n--- Emergency Override Stack ---" << endl;

    if (emergencyStack.empty())
    {
        cout << "No emergencies waiting." << endl;
        return;
    }

    // Copy the stack so the original data remaisn unchanged
    stack<EmergencyEvent> tempStack = emergencyStack;

    while (!tempStack.empty())
    {
        EmergencyEvent emergency = tempStack.top();

        cout << "Emergency: "
             << emergency.getEmergencyType()
             << " | Location: "
             << emergency.getLocation()
             << endl;

        tempStack.pop();
    }
}

// Count high priority events from processed events
int EventManager::countHighPriorityEvents() const
{
    return count_if(processedEvents.begin(), processedEvents.end(), [](const Event &event)
                    { return event.getPriority() >= 3; });
}