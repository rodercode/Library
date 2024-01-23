#pragma once

#include "Book.h"
#include <iostream>
#include <vector>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

using
std::vector,
std::string,
std::cout,
std::endl;

class BookRepository {
private:
    sql::Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *prep_stmt;
    sql::Statement *stmt;
    sql::ResultSet *res;
   

public:
    BookRepository();
    ~BookRepository();

    void executeDelete(string query, int id);
    
    // CRUD Operations
    void create(Book book);
    vector<Book> getAll();
};
