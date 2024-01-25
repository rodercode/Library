#include "User.h"
#include <vector>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

using
std::vector,
std::string,
std::cout,
std::endl;

class UserRepository {
private:
    sql::Driver* driver;
    sql::Connection* con;
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;


public:
    UserRepository();
    ~UserRepository();

};