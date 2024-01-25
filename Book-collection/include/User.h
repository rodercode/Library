#pragma once
#include <string>

using std::string;

class User {
private:
    int userId;
    string username;
    string password;

public:
    User(string username, string password);

    int getUserId();

    string getUsername();

    string getPassword();

    void setUserId(int userId);

    void setUsername(string username);

    void setPassword(string password);
};