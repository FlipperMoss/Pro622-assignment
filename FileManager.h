#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include <fstream>

#include "Engineer.h"
#include "Event.h"

using namespace std;

// ... rest of the code

class FileManager
{
private:
    // Helper functions used to write and read strings
    // when working with binary files.
    static void writeString(
        ofstream &file,
        const string &value);

    static string readString(
        ifstream &file);

public:
    // Save engineers to engineers.dat
    static void saveEngineers(
        const vector<Engineer> &engineers);

    // Load engineers from engineers.dat
    static vector<Engineer> loadEngineers();

    // Save events to events.dat
    static void saveEvents(
        const vector<Event> &events);

    // Load events from events.dat
    static vector<Event> loadEvents();

    // Save historical city logs
    static void saveCityLogs(
        const vector<string> &logs);

    // Load historical city logs
    static vector<string> loadCityLogs();

    // Save configuration settings to a text file
    static void saveConfig(
        string cityName,
        int maxEvents,
        string systemMode);

    // Load and display configuration settings
    static void loadConfig();

    // Export city logs to a CSV file
    static void exportLogsToCSV(
        const vector<string> &logs);
};

#endif