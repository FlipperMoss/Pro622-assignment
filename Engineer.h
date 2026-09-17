#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>
using namespace std;

class Engineer
{
private:
    // Private attributes demonstrate encapsulation
    string engineerID;
    string username;
    string encryptedPassword;
    string clearanceLevel;

public:
    // Constructor
    Engineer(string id, string user, string password, string clearance);

    // Getters
    string getEngineerID() const;
    string getUsername() const;
    string getEncryptedPassword() const;
    string getClearanceLevel() const;

    // Login verification function
    bool checkCredentials(string user, string password) const;
};

#endif