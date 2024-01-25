#include "../include/UserRepository.h"

UserRepository::UserRepository() {
    cout << "Constructor called" << endl;

    // Create a connection
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "test", "P@ssw0rd!");

    // Connect to the MySQL library database
    con->setSchema("librarydb");
}

UserRepository::~UserRepository() {
    cout << "Destructor called" << endl;

    // Deallocate memory for res, stmt and con
    delete res;
    delete con;
    delete prep_stmt;
}

vector<User> UserRepository::getAll() {
    vector<User> users;

    try {
        string querySelectUsers = "SELECT * FROM users";
        prep_stmt = con->prepareStatement(querySelectUsers);
        res = prep_stmt->executeQuery();

        while (res->next()) {
            users.emplace_back(
                res->getInt("user_id"),
                res->getString("username"),
                res->getString("password")
            );
        }
    }
    catch (sql::SQLException& e) {
        cout << "Error: " << e.what();
    }

    return users;
}