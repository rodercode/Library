#pragma once
#include <string>

using std::string;

class Book {
private:
    int bookId;
    string title;
    string author;
    string genreName;

public:
    // Constructors
    Book();
    Book(int bookId, string title, string author, string genreName);

    // Getters and Setters
    int getBookId();
    void setBookId(int bookId);

    string getTitle();
    void setTitle(string title);

    string getAuthor();
    void setAuthor(string author);

    string getGenreName();
    void setGenreName(string genreName);
};
