#include "../include/Book.h"

// Default Constructor
Book::Book()
    : bookId(0), title(""), author(""), genreName(""), userId(0) {}

// Parameterized Constructor
Book::Book(int bookId, string title, string author, string genreName, int userId)
{
    this->bookId = bookId;
    this->title = title;
    this->author = author;
    this->genreName = genreName;
    this->userId = userId;
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

int Book::getUserId() {
	return this->userId;
}

void Book::setUserId(int userId) {
	this->userId = userId;
}