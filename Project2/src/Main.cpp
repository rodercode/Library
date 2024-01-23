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

	vector<Book>getAll() {
		return bookRepository.getAll();
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
			break;
		}

		case 3:
			cout << "Delete book\n";
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