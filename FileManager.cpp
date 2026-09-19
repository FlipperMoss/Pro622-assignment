#include <iostream>
#include <fstream>

#include "FileManager.h"

using namespace std;

// STRING HELPER FUNCTIONS

// Writes a string to a binary file.
//
// We first store the length of the string and then
// store the actual characters.
void FileManager::writeString(
    ofstream &file,
    const string &value)
{
    size_t length = value.length();

    file.write(
        reinterpret_cast<const char *>(&length),
        sizeof(length));

    file.write(
        value.c_str(),
        length);
}

// Reads a string from a binary file.
string FileManager::readString(
    ifstream &file)
{
    size_t length;

    file.read(
        reinterpret_cast<char *>(&length),
        sizeof(length));

    string value(length, '\0');

    file.read(
        &value[0],
        length);

    return value;
}

// ENGINEERS

void FileManager::saveEngineers(
    const vector<Engineer> &engineers)
{
    ofstream file(
        "engineers.dat",
        ios::binary);

    if (!file)
    {
        cout << "Error opening engineers.dat"
             << endl;

        return;
    }

    // Store the number of engineers first.
    size_t count = engineers.size();

    file.write(
        reinterpret_cast<const char *>(&count),
        sizeof(count));

    // Save each engineer.
    for (const Engineer &engineer : engineers)
    {
        writeString(
            file,
            engineer.getEngineerID());

        writeString(
            file,
            engineer.getUsername());

        writeString(
            file,
            engineer.getEncryptedPassword());

        writeString(
            file,
            engineer.getClearanceLevel());
    }

    file.close();

    cout << "Engineers saved to engineers.dat"
         << endl;
}

vector<Engineer> FileManager::loadEngineers()
{
    vector<Engineer> engineers;

    ifstream file(
        "engineers.dat",
        ios::binary);

    if (!file)
    {
        cout << "engineers.dat could not be opened."
             << endl;

        return engineers;
    }

    size_t count;

    file.read(
        reinterpret_cast<char *>(&count),
        sizeof(count));

    // Read each engineer from the file.
    for (size_t i = 0; i < count; i++)
    {
        string id = readString(file);
        string username = readString(file);
        string password = readString(file);
        string clearance = readString(file);

        engineers.push_back(
            Engineer(
                id,
                username,
                password,
                clearance));
    }

    file.close();

    cout << engineers.size()
         << " engineers loaded from engineers.dat"
         << endl;

    return engineers;
}

// EVENTS

void FileManager::saveEvents(
    const vector<Event> &events)
{
    ofstream file(
        "events.dat",
        ios::binary);

    if (!file)
    {
        cout << "Error opening events.dat"
             << endl;

        return;
    }

    // Save the number of events.
    size_t count = events.size();

    file.write(
        reinterpret_cast<const char *>(&count),
        sizeof(count));

    for (const Event &event : events)
    {
        writeString(
            file,
            event.getEventType());

        writeString(
            file,
            event.getLocation());

        int priority = event.getPriority();

        file.write(
            reinterpret_cast<const char *>(&priority),
            sizeof(priority));
    }

    file.close();

    cout << "Events saved to events.dat"
         << endl;
}

vector<Event> FileManager::loadEvents()
{
    vector<Event> events;

    ifstream file(
        "events.dat",
        ios::binary);

    if (!file)
    {
        cout << "events.dat could not be opened."
             << endl;

        return events;
    }

    size_t count;

    file.read(
        reinterpret_cast<char *>(&count),
        sizeof(count));

    for (size_t i = 0; i < count; i++)
    {
        string type = readString(file);
        string location = readString(file);

        int priority;

        file.read(
            reinterpret_cast<char *>(&priority),
            sizeof(priority));

        events.push_back(
            Event(
                type,
                location,
                priority));
    }

    file.close();

    cout << events.size()
         << " events loaded from events.dat"
         << endl;

    return events;
}

// CITY LOGS

void FileManager::saveCityLogs(
    const vector<string> &logs)
{
    ofstream file(
        "city_logs.dat",
        ios::binary);

    if (!file)
    {
        cout << "Error opening city_logs.dat"
             << endl;

        return;
    }

    size_t count = logs.size();

    file.write(
        reinterpret_cast<const char *>(&count),
        sizeof(count));

    // Save every historical city log.
    for (const string &log : logs)
    {
        writeString(file, log);
    }

    file.close();

    cout << "City logs saved to city_logs.dat"
         << endl;
}

vector<string> FileManager::loadCityLogs()
{
    vector<string> logs;

    ifstream file(
        "city_logs.dat",
        ios::binary);

    if (!file)
    {
        cout << "city_logs.dat could not be opened."
             << endl;

        return logs;
    }

    size_t count;

    file.read(
        reinterpret_cast<char *>(&count),
        sizeof(count));

    for (size_t i = 0; i < count; i++)
    {
        logs.push_back(
            readString(file));
    }

    file.close();

    cout << logs.size()
         << " city logs loaded from city_logs.dat"
         << endl;

    return logs;
}

// CONFIGURATION

void FileManager::saveConfig(
    string cityName,
    int maxEvents,
    string systemMode)
{
    // config.txt is a normal text file rather than
    // a binary file because configuration values are
    // easy to read and edit as text.

    ofstream file("config.txt");

    if (!file)
    {
        cout << "Error opening config.txt"
             << endl;

        return;
    }

    file << "CITY_NAME=" << cityName << endl;
    file << "MAX_EVENTS=" << maxEvents << endl;
    file << "SYSTEM_MODE=" << systemMode << endl;

    file.close();

    cout << "Configuration saved to config.txt"
         << endl;
}

void FileManager::loadConfig()
{
    ifstream file("config.txt");

    if (!file)
    {
        cout << "config.txt could not be opened."
             << endl;

        return;
    }

    string line;

    cout << "\n--- Configuration ---" << endl;

    // Read the configuration one line at a time.
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// CSV EXPORT

void FileManager::exportLogsToCSV(
    const vector<string> &logs)
{
    ofstream file("city_logs.csv");

    if (!file)
    {
        cout << "Error creating city_logs.csv"
             << endl;

        return;
    }

    // CSV header
    file << "Log_ID,City_Log" << endl;

    // Export each log.
    for (size_t i = 0; i < logs.size(); i++)
    {
        file << i + 1
             << ",\""
             << logs[i]
             << "\""
             << endl;
    }

    file.close();

    cout << "City logs exported to city_logs.csv"
         << endl;
}