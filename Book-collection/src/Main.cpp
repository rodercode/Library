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


		Book newBook(0, title, author, genreName);
		bookRepository.create(newBook);
	}

 		Book getById() {
		int bookId;
		getUserInput("Enter book id: ", bookId);
		return bookRepository.getById(bookId);
	}

	vector<Book>getAll() {
		return bookRepository.getAll();
	}

	void updateById() {
		int bookId;
		string title, author, genreName;
		
		getUserInput("Enter book id: ", bookId);
		getUserInput("Enter title: ", title);
		getUserInput("Enter author: ", author);
		getUserInput("Enter genre: ", genreName);
			
		Book updatedBook(0, title, author, genreName);
		bookRepository.updateById(bookId, updatedBook);
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
		{
			break;
		}
			
		case 4:
		{
			displayBooks(bookService.getAll());
			cout << endl;
			bookService.deleteById();
			break;
		}

		case 5:
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