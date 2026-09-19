#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>

#include "ReportManager.h"

using namespace std;

// Adds an event response time to the vector.
void ReportManager::addResponseTime(double time)
{
    responseTimes.push_back(time);
}

// Adds an emergency type to the vector.
void ReportManager::addEmergencyType(string type)
{
    emergencyTypes.push_back(type);
}

// Adds a system load value to the vector.
void ReportManager::addSystemLoad(double load)
{
    systemLoads.push_back(load);
}

void ReportManager::reportTotalEvents() const
{
    cout << "\n--- Total Events Processed ---" << endl;

    // The number of response times represents the number
    // of events that have been processed.
    cout << "Total events processed: "
         << responseTimes.size()
         << endl;
}

void ReportManager::reportMostCommonEmergency() const
{
    cout << "\n--- Most Common Emergency ---" << endl;

    if (emergencyTypes.empty())
    {
        cout << "No emergency data available." << endl;
        return;
    }

    // A map is used to store each emergency type and
    // the number of times it occurred.
    map<string, int> emergencyCounts;

    // Iterator is used to traverse the emergency vector.
    for (vector<string>::const_iterator it =
             emergencyTypes.begin();
         it != emergencyTypes.end();
         ++it)
    {
        // Increase the count for the current emergency.
        emergencyCounts[*it]++;
    }

    // Find the emergency with the highest count.
    auto mostCommon = max_element(
        emergencyCounts.begin(),
        emergencyCounts.end(),
        [](const pair<string, int> &first,
           const pair<string, int> &second)
        {
            return first.second < second.second;
        });

    cout << "Most common emergency: "
         << mostCommon->first << endl;

    cout << "Occurrences: "
         << mostCommon->second << endl;
}

void ReportManager::reportAverageResponseTime() const
{
    cout << "\n--- Average Response Time ---" << endl;

    if (responseTimes.empty())
    {
        cout << "No response time data available."
             << endl;
        return;
    }

    // Accumulate all response times.
    double totalTime = accumulate(
        responseTimes.begin(),
        responseTimes.end(),
        0.0);

    // Calculate the average response time.
    double average =
        totalTime / responseTimes.size();

    cout << "Average response time: "
         << average
         << " seconds"
         << endl;
}

void ReportManager::reportSystemLoad() const
{
    cout << "\n--- System Load Summary ---" << endl;

    if (systemLoads.empty())
    {
        cout << "No system load data available."
             << endl;
        return;
    }

    // Find the lowest system load.
    auto lowest = min_element(
        systemLoads.begin(),
        systemLoads.end());

    // Find the highest system load.
    auto highest = max_element(
        systemLoads.begin(),
        systemLoads.end());

    // Calculate the total system load.
    double totalLoad = accumulate(
        systemLoads.begin(),
        systemLoads.end(),
        0.0);

    // Calculate the average system load.
    double averageLoad =
        totalLoad / systemLoads.size();

    cout << "Lowest system load: "
         << *lowest << "%"
         << endl;

    cout << "Highest system load: "
         << *highest << "%"
         << endl;

    cout << "Average system load: "
         << averageLoad << "%"
         << endl;
}

void ReportManager::generateReport() const
{
    cout << "\n======================================"
         << endl;

    cout << "       NEOVERSE SYSTEM REPORT"
         << endl;

    cout << "======================================"
         << endl;

    reportTotalEvents();

    reportMostCommonEmergency();

    reportAverageResponseTime();

    reportSystemLoad();

    cout << "\n======================================"
         << endl;
}