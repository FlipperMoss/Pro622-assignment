#ifndef ALGORITHMMANAGER_H
#define ALGORITHMMANAGER_H

#include <vector>
#include <string>

using namespace std;

class AlgorithmManager
{
public:
    // Sort sensor readings from lowest to highest.
    void sortSensorData(vector<double> &readings);

    // Find a specific event in a vector.
    bool findEvent(
        const vector<string> &events,
        const string &eventName);

    // Find the lowest sensor reading.
    double findLowestReading(
        const vector<double> &readings);

    // Find the highest sensor reading.
    double findHighestReading(
        const vector<double> &readings);

    // Count critical alerts.
    int countCriticalAlerts(
        const vector<int> &alertLevels);
};

#endif