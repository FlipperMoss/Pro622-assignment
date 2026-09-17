#include <iostream>
#include "CityData.h"

using namespace std;

CityData::CityData()
{
    // The vector and list are automatically initialised
}

// Sensor and historical logs and readings
void CityData::addSensorReading(double reading)
{
    dailySensorReadings.push_back(reading);
}

void CityData::addCityLog(string log)
{
    historicalLogs.push_back(log);
}

// Display all readings
void CityData::displaySensorReadings() const
{
    cout << "\n--- Daily Sensor Readings ---" << endl;

    for (size_t i = 0; i < dailySensorReadings.size(); i++)
    {
        cout << "Reading " << i + 1 << ": " << dailySensorReadings[i] << endl;
    }
}

void CityData::displayHistoricalLogs() const
{
    cout << "\n--- Historical City Logs ---" << endl;

    for (const string &log : historicalLogs)
    {
        cout << "- " << log << endl;
    }
}