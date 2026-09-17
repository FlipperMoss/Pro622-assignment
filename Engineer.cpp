#include "Engineer.h"

// Constructor used to create a new Engineer obkect

Engineer::Engineer(string id, string user, string password, string clearance)
{
    engineerID = id;
    username = user;
    encryptedPassword = password;
    clearanceLevel = clearance;
}

// Returns the engineer's ID
string Engineer::getEngineerID() const
{
    return engineerID;
}

// Returns the username
string Engineer::getUsername() const
{
    return username;
}

// Return the stored encrypted password
string Engineer::getEncryptedPassword() const
{
    return encryptedPassword;
}

// Return the engineer's clearance level
string Engineer::getClearanceLevel() const
{
    return clearanceLevel;
}

// Checks whether the username and password match
bool Engineer::checkCredentials(string user, string password) const
{
    return username == user && encryptedPassword == password;
}
