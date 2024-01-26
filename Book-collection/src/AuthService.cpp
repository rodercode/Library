#include <iostream>
#include "../include/AuthService.h"

extern bool isLogged;
extern User currentUser;

template<typename T>
void getUserInput(const string& prompt, T& input) {
    cout << prompt;

    if (!(cin >> input)) {
        cin.clear();
        cin.ignore(100, '\n');
    }
}

AuthService::AuthService() {
	std::cout << "Allocation in AuthService" << std::endl;
    userRepository = new UserRepository();
}

AuthService::~AuthService() {
	std::cout << "Deallocation in AuthService" << std::endl;
	delete userRepository;
}



void AuthService::login() {
    getUserInput("Enter username: ", credentials.username);
    getUserInput("Enter password: ", credentials.password);

    for (User user : userRepository->getAll()) {
        if (credentials.username == user.getUsername() && credentials.password == user.getPassword()){
            setCurrentUser(user);
            std::cout << "Login successful!\n";
            isLogged = true;
            return;
        }
    }
        
    std::cout << "Invalid credentials. Please try again.\n";
}



void AuthService::registrate() {
    getUserInput("Enter username: ", credentials.username);
    getUserInput("Enter password: ", credentials.password);

    for (User user : userRepository->getAll()) {
        if (credentials.username == user.getUsername() && credentials.password == user.getPassword()) {
            std::cout << "User already exists. Please try again.\n";
            return;
        }
    }

    User newUser(0, credentials.username, credentials.password);
    userRepository->create(newUser);
}

void AuthService::checkIfLogged() {
    if (!isLogged && currentUser.getUserId() == 0){
        currentUser.setUserId(0);
        currentUser.setUsername("");
        currentUser.setPassword("");	
	}
}


void AuthService::setCurrentUser(User& user) {
    currentUser.setUserId(user.getUserId());
    currentUser.setUsername(user.getUsername());
    currentUser.setPassword(user.getPassword());
}

