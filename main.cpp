#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Engineer.h"
#include "CityData.h"
#include "EventManager.h"
#include "PowerSystem.h"
#include "TransportSystem.h"
#include "HealthSystem.h"
#include "SecuritySystem.h"
#include "AlgorithmManager.h"

using namespace std;

// This is a basic password encryption for demonstration purposes
// This shifts each character by 3 positions.

string encryptPassword(const string &password)
{
    string encrypted = password;

    for (char &character : encrypted)
    {
        character = character + 3;
    }

    return encrypted;
}

int main()
{
    // Vector is used to store all registered engineers
    vector<Engineer> enginneers;

    // Sample engineers
    enginneers.push_back(
        Engineer("ENG001", "neo", encryptPassword("Lunatic12"), "Medium"));

    enginneers.push_back(
        Engineer("ENG002", "trinity", encryptPassword("dh#fjdvs12@mcsaj"), "High"));

    enginneers.push_back(
        Engineer("ENG003", "redbull", encryptPassword("redbull101"), "Low"));

    string username;
    string password;

    cout << "==============================" << endl;
    cout << "          NEOVERSE CITY SYSTEM" << endl;
    cout << "          AI ENGINEER LOGIN" << endl;
    cout << "==============================" << endl;

    cout << "\nUsername: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    // Encrypt the password entered by the user before comparing it with the stored encrypted password
    string encryptedInput = encryptPassword(password);

    auto engineerFound = find_if(
        enginneers.begin(),
        enginneers.end(),
        [&](const Engineer &enginneer)
        {
            return enginneer.checkCredentials(username, encryptedInput);
        });

    // IF engineer was found, authentication is successful
    if (engineerFound != enginneers.end())
    {
        cout << "\nLogin Successful!" << endl;
        cout << "Engineer ID: " << engineerFound->getEngineerID() << endl;
        cout << "Clearance Level: " << engineerFound->getClearanceLevel() << endl;
        cout << "\nAccess granted to NeoVerse City System." << endl;
    }
    else
    {
        // No matching creadentials found.
        cout << "\nLogin Failed!" << endl;
        cout << "Invalid username or password." << endl;
    }

    // CityData Object
    CityData cityData;
    // samples
    cityData.addSensorReading(75.6);
    cityData.addSensorReading(43.5);
    cityData.addSensorReading(93.1);
    cityData.addSensorReading(23.9);

    cityData.displaySensorReadings();

    // REMOVE SENSOR DATA
    // index 1 represents the second element
    cityData.removeSensorReading(1);
    // Display the vecotr again
    cityData.displaySensorReadings();

    cityData.addCityLog("Power consumption increased during peak hours.");
    cityData.addCityLog("Traffic congeestion detected in sector 4.");
    cityData.addCityLog("Weather alert received from monitoring station.");

    cityData.displayHistoricalLogs();

    // REMOVE OUTDATED DATA
    cityData.removeOldestLog();

    cityData.displayHistoricalLogs();

    // Question 3

    EventManager eventManager;

    cout << "\n================================" << endl;
    cout << "\n==================================" << endl;
    cout << "===============================" << endl;

    // 3.1

    // Events are added this order
    eventManager.addEvent(
        Event("Traffic accident", "Section 1", 3));

    eventManager.addEvent(
        Event("Power Failure", "Section 3", 5));

    eventManager.addEvent(
        Event("Weather Alert", "Section 2", 4));

    // Display events in the order they are waiting
    eventManager.displayEvents();

    // Process the first event that arrived
    eventManager.processNextEvent();

    eventManager.processNextEvent();

    // 3.2

    // Emergencies are added to the stack
    eventManager.addEmergency(
        EmergencyEvent("Major Power Failure", "Sector 7"));

    eventManager.addEmergency(
        EmergencyEvent("City Network Attack", "Sector 2"));

    eventManager.addEmergency(
        EmergencyEvent("Severe Weather", "Sector 4"));

    // Display events
    eventManager.displayEmergencies();

    eventManager.processEmergency();
    eventManager.processEmergency();

    // STL Algorithm

    // Displays the number of processed high priority events
    cout << "\nHigh priority events processed: "
         << eventManager.countHighPriorityEvents()
         << endl;

    // QUESTION 4 - OBJECT-ORIENTED CITY ARCHITECTURE

    cout << "\n======================================" << endl;
    cout << "       CITY COMPONENT SYSTEM" << endl;
    cout << "======================================" << endl;

    PowerSystem power(
        101,
        "NeoVerse Power System",
        95.5);

    TransportSystem transport(
        102,
        "NeoVerse Transport System",
        75);

    HealthSystem health(
        103,
        "NeoVerse Health System",
        8);

    SecuritySystem security(
        104,
        "NeoVerse Security System",
        2);

    power.activate();
    transport.activate();
    health.activate();
    security.activate();

    cout << "\nComponent Status:" << endl;

    cout << "Power: "
         << power.getStatus() << endl;

    cout << "Transport: "
         << transport.getStatus() << endl;

    cout << "Health: "
         << health.getStatus() << endl;

    cout << "Security: "
         << security.getStatus() << endl;

    CityComponent *components[4] =
        {
            &power,
            &transport,
            &health,
            &security};

    cout << "\n--- Processing City Events ---" << endl;

    for (int i = 0; i < 4; i++)
    {
        components[i]->processEvent();

        cout << endl;
    }

    security.deactivate();

    cout << "Security status: "
         << security.getStatus()
         << endl;

    // QUESTION 5
    cout << "\n======================================" << endl;
    cout << "       STL ALGORITHMS" << endl;
    cout << "======================================" << endl;

    AlgorithmManager algorithms;

    // Create some unsorted sensor readings.
    vector<double> sensorReadings =
        {
            82.5,
            45.7,
            91.3,
            63.2,
            77.8,
            52.4};

    cout << "\nOriginal sensor readings:" << endl;

    for (double reading : sensorReadings)
    {
        cout << reading << " ";
    }

    cout << endl;

    // 1. SORT

    algorithms.sortSensorData(sensorReadings);

    cout << "Sorted sensor readings:" << endl;

    for (double reading : sensorReadings)
    {
        cout << reading << " ";
    }

    cout << endl;

    // 2. MIN_ELEMENT

    double lowest =
        algorithms.findLowestReading(sensorReadings);

    cout << "\nLowest sensor reading: "
         << lowest << endl;

    // 3. MAX_ELEMENT

    double highest =
        algorithms.findHighestReading(sensorReadings);

    cout << "Highest sensor reading: "
         << highest << endl;

    // EVENT SEARCH

    // Create a list of city events.
    vector<string> cityEvents =
        {
            "Traffic Accident",
            "Power Failure",
            "Network Overload",
            "Weather Alert"};

    // 4. FIND

    string searchEvent = "Power Failure";

    bool eventFound =
        algorithms.findEvent(cityEvents, searchEvent);

    if (eventFound)
    {
        cout << "\nEvent found: "
             << searchEvent << endl;
    }
    else
    {
        cout << "\nEvent not found: "
             << searchEvent << endl;
    }

    // CRITICAL ALERTS

    // Alert levels:
    // 1 = Low
    // 2 = Medium
    // 3 = High
    // 4 = Critical

    vector<int> alertLevels =
        {
            1,
            3,
            2,
            4,
            3,
            1,
            2};

    // 5. COUNT_IF

    int criticalAlerts =
        algorithms.countCriticalAlerts(alertLevels);

    cout << "\nNumber of critical/high alerts: "
         << criticalAlerts << endl;

    return 0;
}