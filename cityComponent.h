#ifndef CITYCOMPONENT_H
#define CITYCOMPONENT_H

#include <string>

using namespace std;

class CityComponent
{
private:
    // Private data demonstrates encapsulation.
    int componentID;
    string name;
    bool active;

public:
    // Constructor
    CityComponent(int id, string componentName);

    // Virtual destructor is important when using polymorphism.
    virtual ~CityComponent();

    // Activate the city component.
    void activate();

    // Deactivate the city component.
    void deactivate();

    // Return the current status of the component.
    string getStatus() const;

    // Virtual function that will be overridden by
    // every derived class.
    virtual void processEvent() = 0;
};

#endif