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
    delete prep_stmt;
}

void BookRepository::executeCreate(string queary) {
    try {
        stmt->execute(queary);
    }
    catch (sql::SQLException& e) {
        std::cout << "Error: " << e.what();
        return;
    }
}

void BookRepository::executeSelect(string query) {
    try {
        res = stmt->executeQuery(query);
    }
    catch (sql::SQLException& e) {
        std::cout << "Error: " << e.what();
        return;
    }
}

void BookRepository::executeDelete(string query, int id) {
    try {
		prep_stmt = con->prepareStatement(query);
		prep_stmt->setInt(1, id);
		prep_stmt->execute();

    }catch(sql::SQLException& e) {
        std::cout << "Error: " << e.what();
		return;
    }
}

// CRUD Operations
void BookRepository::create(Book book) {
    try {
        string queryInsertBook = "INSERT INTO books (title, author, genre_name) VALUES (?, ?, ?)";
        prep_stmt = con->prepareStatement(queryInsertBook);

        prep_stmt->setString(1, book.getTitle());
        prep_stmt->setString(2, book.getAuthor());
        prep_stmt->setString(3, book.getGenreName());

        prep_stmt->execute();
    }
    catch (sql::SQLException& e) {
        std::cout << "Error: " << e.what();
    }

    cout << "Book with name: " << book.getTitle() << " was successfully created" << endl;
}

Book BookRepository::getById(int id) {
    try {
        string query = "SELECT * FROM books WHERE book_id = ?";
        prep_stmt = con->prepareStatement(query);
        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();

        if (res->next()) {
            return Book(
                res->getInt("book_id"),
                res->getString("title"),
                res->getString("author"),
                res->getString("genre_name")
            );
        }
        else {
            cout << "No book found with ID: " << id << endl;
        }
    }
    catch (sql::SQLException& e) {
		std::cout << "Error: " << e.what();
    }
}

vector<Book> BookRepository::getAll(){
    executeSelect("SELECT * FROM books");
    vector<Book> books;
    
    try {
        string querySelectBooks = "SELECT * FROM books";
        prep_stmt = con->prepareStatement(querySelectBooks);
        res = prep_stmt->executeQuery();    
        
    while (res->next()) {
        books.emplace_back(
            res->getInt("book_id"),
            res->getString("title"),
            res->getString("author"),
            res->getString("genre_name")
        );
        }
    }
    catch (sql::SQLException& e) {
        cout << "Error: " << e.what();
    }

    return books;
}

void BookRepository::updateById(int bookId, Book& book) {

    try {
        string getBookQuery = "SELECT * FROM books WHERE book_id = ?";
        prep_stmt = con->prepareStatement(getBookQuery);
        prep_stmt->setInt(1, bookId);
        res = prep_stmt->executeQuery();

        if (!res->next()) {
            cout << "No book found with ID: " << bookId << endl;
            return;
        }

        string updateBookQuery = 
            "UPDATE books SET title = ?, author = ?, genre_name = ? WHERE book_id = ?";
        
        prep_stmt = con->prepareStatement(updateBookQuery);

        prep_stmt->setString(1, book.getTitle());
        prep_stmt->setString(2, book.getAuthor());
        prep_stmt->setString(3, book.getGenreName());
        prep_stmt->setInt(4, bookId);
        
        prep_stmt->execute();

        cout << "Book with id: " << bookId << " was successfully updated" << endl;
    }
    catch (sql::SQLException& e) {
        cout << "Error: " << e.what();
    }
}

void BookRepository::deleteById(int bookId) {
    
    try {
        string getBookQuery = "SELECT * FROM books WHERE book_id = ?";
        prep_stmt = con->prepareStatement(getBookQuery);
        prep_stmt->setInt(1, bookId);
        res = prep_stmt->executeQuery();

        if (!res->next()) {
            cout << "No book found with ID: " << bookId << endl;
            return;
        }
        
        string deleteQuery = "DELETE FROM books WHERE book_id = ?";
        prep_stmt = con->prepareStatement(deleteQuery);
        prep_stmt->setInt(1, bookId);
        prep_stmt->execute();
    }
    catch (sql::SQLException& e) {
        cout << "Error: " << e.what();
    }

    cout << "Book with id: " << bookId << " was successfully deleted" << endl;
}