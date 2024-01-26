#pragma once
#include <iostream>
#include "UserRepository.h"

using 
    std::string,
    std::cin,
    std::cout;

struct Credentials {
    string username = "";
    string password = "";
};

class AuthService {
private:
    Credentials credentials;
    UserRepository* userRepository;

public:
    AuthService();
    ~AuthService();

	void login();
	void registrate();
};