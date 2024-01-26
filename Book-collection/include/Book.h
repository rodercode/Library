#pragma once
#include <string>

using std::string;

class Book {
private:
    int bookId;
    string title;
    string author;
    string genreName;
    int userId;

public:
    // Constructors
    Book();
    Book(int bookId, string title, string author, string genreName, int userId);

    // Getters and Setters
    int getBookId();
    void setBookId(int bookId);

    string getTitle();
    void setTitle(string title);

    string getAuthor();
    void setAuthor(string author);

    string getGenreName();
    void setGenreName(string genreName);

    int getUserId();
    void setUserId(int userId);
};
