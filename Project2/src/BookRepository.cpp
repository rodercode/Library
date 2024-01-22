#include "../include/BookRepository.h"

BookRepository::BookRepository() {
    cout << "Constructor called" << endl;
    
    // Create a connection
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "test", "P@ssw0rd!");
    
    // Connect to the MySQL library database
    con->setSchema("librarydb");
    
    // Create statement object to be able to execute SQL queries
    stmt = con->createStatement();
}

BookRepository::~BookRepository() {
    cout << "Destructor called" << endl;
    // Deallocate memory for res, stmt and con
    delete res;
    delete stmt;
    delete con;
}

void BookRepository::execute(string query) {
    try {
        res = stmt->executeQuery(query);
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: " << e.what();
        return;
    }
}
