// Include header files
#include "../include/BookRepository.h"
#include "../include/UserInterface.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using
std::cout,
std::cin,
std::endl,
std::string,
std::vector,
std::istringstream,
std::ios;


template<typename T>
void getUserInput(const string& prompt, T& input) {
	cout << prompt;
	
	if(!(cin >> input)){
		cin.clear();
		cin.ignore(100, '\n');
	}
}


class BookService {
private:
		BookRepository bookRepository;

public:
	BookService(){}

	void create() {
		string title, author, genreName;
		getUserInput("Enter title: ", title);
		getUserInput("Enter author: ", author);
		getUserInput("Enter genre: ", genreName);

		bookRepository.create(Book(0, title, author, genreName));
	}

	Book getById() {
		int bookId;
		getUserInput("Enter book id: ", bookId);
		return bookRepository.getById(bookId);
	}

	vector<Book>getAll() {
		return bookRepository.getAll();
	}

	void deleteById() {
		int bookId;
		getUserInput("Enter book id: ", bookId);
		bookRepository.deleteById(bookId);
	}
};

// Global variables
int choice;
BookService bookService;
bool isRunning = true;

// Main
int main() {

	while (isRunning) {
		displayMenu();
		getUserInput("Enter your choice (1-4): ", choice);

		switch (choice) {
		case 1:
		{
			cout << endl;
			displayBooks(bookService.getAll());
			break;
		}
		case 2:
		{
			bookService.create();
			break;
		}

		case 3:
			displayBooks(bookService.getAll());
			cout << endl;
			bookService.deleteById();
			break;

		case 4:
		{
			cout << "Exiting program...\n";
			isRunning = false;
			break;
		}

		default:
			cout << "Invalid input. Please try again." << '\n';
			
		}

		cout << endl;
	}

	return 0;
}