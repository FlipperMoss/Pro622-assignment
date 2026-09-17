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

public:
    // Constructor
    CityData();

    void addSensorReading(double reading);

    // Add a new city log to the linked list
    void addCityLog(string log);

    // Display
    void displaySensorReadings() const;
    void displayHistoricalLogs() const;
};

#endif