#include <iostream>
#include <algorithm>
#include "AlgorithmManager.h"

using namespace std;

// Sorts sensor readings from lowest to highest.
void AlgorithmManager::sortSensorData(
    vector<double> &readings)
{
    // STL sort rearranges the vector into ascending order.
    sort(readings.begin(), readings.end());

    cout << "Sensor readings sorted successfully."
         << endl;
}
// FIND

// Searches for a specific event.
bool AlgorithmManager::findEvent(
    const vector<string> &events,
    const string &eventName)
{
    // find searches the vector for the requested event.
    auto result = find(
        events.begin(),
        events.end(),
        eventName);

    return result != events.end();
}
// MIN_ELEMENT

// Finds the lowest sensor reading.
double AlgorithmManager::findLowestReading(
    const vector<double> &readings)
{
    if (readings.empty())
    {
        return 0;
    }
    auto result = min_element(
        readings.begin(),
        readings.end());

    return *result;
}

// MAX_ELEMENT

// Finds the highest sensor reading.
double AlgorithmManager::findHighestReading(
    const vector<double> &readings)
{
    if (readings.empty())
    {
        return 0;
    }

    auto result = max_element(
        readings.begin(),
        readings.end());

    return *result;
}

// COUNT_IF

// Counts how many alerts are considered critical.
int AlgorithmManager::countCriticalAlerts(
    const vector<int> &alertLevels)
{
    // count_if checks each alert and counts those
    // with a severity level of 3 or higher.
    return count_if(
        alertLevels.begin(),
        alertLevels.end(),
        [](int level)
        {
            return level >= 3;
        });
}