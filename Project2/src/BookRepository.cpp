#include "../include/BookRepository.h"
#include "../include/Book.h"

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

void BookRepository::execute(string queary) {
    try {
        stmt->execute(queary);
    }
    catch (sql::SQLException& e) {
        std::cout << "Error: " << e.what();
        return;
    }
}

void BookRepository::executeQuery(string query) {
    try {
        res = stmt->executeQuery(query);
    }
    catch (sql::SQLException& e) {
        std::cout << "Error: " << e.what();
        return;
    }
}

// CRUD Operations
void BookRepository::create(Book book) {
    string insertBook =
        "INSERT INTO books "
        "(title, author, genre_name) VALUES"
        "('" 
        + book.getTitle() + "', '" 
        + book.getAuthor() + "', '" 
        + book.getGenreName() +
        "')";

    execute(insertBook);
    cout << "Book created successfully" << endl;
}


vector<Book> BookRepository::getAll(){
    executeQuery("SELECT * FROM books");
    vector<Book> books;
    while (res->next()) {
        books.emplace_back(
            res->getInt("book_id"),
            res->getString("title"),
            res->getString("author"),
            res->getString("genre_name")
        );
    }

    return books;
}