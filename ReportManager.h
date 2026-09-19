#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include <vector>
#include <string>

using namespace std;

class ReportManager
{
private:
    // Stores the response time for each processed event.
    vector<double> responseTimes;

    // Stores the type of each emergency.
    vector<string> emergencyTypes;

    // Stores the system load values.
    vector<double> systemLoads;

public:
    // Add a response time to the report data.
    void addResponseTime(double time);

    // Add an emergency type to the report data.
    void addEmergencyType(string type);

    // Add a system load value.
    void addSystemLoad(double load);

    // Generate all system reports.
    void generateReport() const;

    // Individual reports.
    void reportTotalEvents() const;
    void reportMostCommonEmergency() const;
    void reportAverageResponseTime() const;
    void reportSystemLoad() const;
};

#endif