#include "../include/UserRepository.h"

BookRepository::BookRepository() {
    cout << "Constructor called" << endl;

    // Create a connection
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "test", "P@ssw0rd!");

    // Connect to the MySQL library database
    con->setSchema("librarydb");
}

BookRepository::~BookRepository() {
    cout << "Destructor called" << endl;

    // Deallocate memory for res, stmt and con
    delete res;
    delete con;
    delete prep_stmt;
}