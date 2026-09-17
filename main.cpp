#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Engineer.h"

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

    return 0;
}