#include "../include/BookService.h"

extern User currentUser;

template<typename T>
void getUserInput(const string& prompt, T& input) {
	cout << prompt;

	if (!(cin >> input)) {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

// Constructor
BookService::BookService() {
	bookRepository = new BookRepository();
}

// Destructor
BookService::~BookService() {
	delete bookRepository;
}

// CRUD operations
void BookService::create() {
	string title, author, genreName;
	getUserInput("Enter title: ", title);
	getUserInput("Enter author: ", author);
	getUserInput("Enter genre: ", genreName);


	Book newBook(0, title, author, genreName, currentUser.getUserId());
	bookRepository->create(newBook);
}

Book BookService::getById() {
	int bookId;
	getUserInput("Enter book id: ", bookId);
	return bookRepository->getById(bookId);
}

vector<Book> BookService::getAll() {
	return bookRepository->getAll(currentUser.getUserId());
}

void BookService::updateById() {
	int bookId;		
	string title, author, genreName;

	getUserInput("Enter book id: ", bookId);
	getUserInput("Enter title: ", title);
	getUserInput("Enter author: ", author);
	getUserInput("Enter genre: ", genreName);


	Book updatedBook(bookId, title, author, genreName, currentUser.getUserId());
	bookRepository->updateById(updatedBook);
}

void BookService::deleteById() {
	int bookId;
	getUserInput("Enter book id: ", bookId);
	bookRepository->deleteById(bookId, currentUser.getUserId());
}

