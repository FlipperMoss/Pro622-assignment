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
    // We use this as a vector is suitable because sensor readings can be stored sequentually and accessed direclty using an index
    // So if we want the 100th reading we can accesss it directly rather than starting from the beginning.
    dailySensorReadings.push_back(reading);
    cout << "Sensor reading added: " << reading << endl;
}

// Removes sensor reading from the vector
void CityData::removeSensorReading(int index)
{
    // Checks that the requested index exists before removing it.
    if (index > 0 && index < dailySensorReadings.size())
    {
        dailySensorReadings.erase(dailySensorReadings.begin() + index);

        cout << "Sensor reading removed." << endl;
    }
}

void CityData::addCityLog(string log)
{
    historicalLogs.push_back(log);
    // This is efficient and for traversal, we simply go through each log.
}

// Removes the olderst log from the linked list.
void CityData::removeOldestLog()
{
    if (!historicalLogs.empty())
    {
        // The first item represents the olderst log
        historicalLogs.pop_front();

        cout << "Oldest city log removed" << endl;
    }
    else
    {
        cout << "No historical logs available." << endl;
    }
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