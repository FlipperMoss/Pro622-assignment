#ifndef CITYDATA_H
#define CITYDATA_H

#include <vector>
#include <list>
#include <iostream>

using namespace std;

class CityData
{
private:
    vector<double> dailySensorReadings;
    list<string> historicalLogs;
    // A linked list is suitable for historical logs because the logs can continue growing dynamucally. The container does not require us to specify a fixed maximum number of logs.

public:
    // Constructor
    CityData();

    void addSensorReading(double reading);
    void removeSensorReading(int index);

    // Add a new city log to the linked list
    void addCityLog(string log);
    void removeOldestLog();

    // Display
    void displaySensorReadings() const;
    void displayHistoricalLogs() const;
};

#endif