#include "../include/BookService.h"

template<typename T>
void getUserInput(const string& prompt, T& input) {
	cout << prompt;

	if (!(cin >> input)) {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

// Constructor
BookService::BookService() {}

// CRUD operations
void BookService::create() {
	string title, author, genreName;
	getUserInput("Enter title: ", title);
	getUserInput("Enter author: ", author);
	getUserInput("Enter genre: ", genreName);


	Book newBook(0, title, author, genreName);
	bookRepository.create(newBook);
}

Book BookService::getById() {
	int bookId;
	getUserInput("Enter book id: ", bookId);
	return bookRepository.getById(bookId);
}

vector<Book> BookService::getAll() {
	return bookRepository.getAll();
}

void BookService::updateById() {
	int bookId;
	string title, author, genreName;

	getUserInput("Enter book id: ", bookId);
	getUserInput("Enter title: ", title);
	getUserInput("Enter author: ", author);
	getUserInput("Enter genre: ", genreName);

	Book updatedBook(0, title, author, genreName);
	bookRepository.updateById(bookId, updatedBook);
}

void BookService::deleteById() {
	int bookId;
	getUserInput("Enter book id: ", bookId);
	bookRepository.deleteById(bookId);
}

