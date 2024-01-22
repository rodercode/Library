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

class BookService {
private:
		BookRepository bookRepository;

public:
	BookService(){}

	vector<Book>getAll() {
		return bookRepository.getAll();
	}
};




// Global variables
int choice;

// Main
int main() {
	
	displayMenu();
	getUserInput(choice);

	if (choice == 1) {
		cout << endl;
		displayBooks(bookService.getAll());
	}
	return 0;
}