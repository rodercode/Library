#include "../include/Book.h"

// Default Constructor
Book::Book()
    : bookId(0), title(""), author(""), genreName("") {}

// Parameterized Constructor
Book::Book(int bookId, string title, string author, string genreName)
{
    this->bookId = bookId;
    this->title = title;
    this->author = author;
    this->genreName = genreName;
}

// Getters and Setters

int Book::getBookId() {
    return this->bookId;
}

void Book::setBookId(int bookId) {
    this->bookId = bookId;
}

string Book::getTitle() {
    return this->title;
}

void Book::setTitle(string title) {
    this->title = title;
}

string Book::getAuthor() {
    return this->author;
}

void Book::setAuthor(string author) {
    this->author = author;
}

string Book::getGenreName() {
    return this->genreName;
}

void Book::setGenreName(string genreName) {
    this->genreName = genreName;
}