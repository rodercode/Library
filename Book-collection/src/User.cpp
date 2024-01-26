#include "../include/User.h"

// Default Constructor
User::User()
    :userId(0), username(""), password("") {}

// Parameterized Constructor
User::User(int userId, string username, string password){
    this->userId = userId;
    this->username = username;
    this->password = password;
}

// Getters and Setters
int User::getUserId() {
    return this->userId;
}

void User::setUserId(int userId) {
    this->userId = userId;
}

string User::getUsername() {
    return this->username;
}

void User::setUsername(string username) {
    this->username = username;
}

string User::getPassword() {
    return this->password;
}

void User::setPassword(string password) {
    this->password = password;
}