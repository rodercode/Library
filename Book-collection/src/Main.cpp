// Include header files
#include "../include/UserInterface.h"
#include "../include/BookService.h"

template<typename T>
void getUserInput(const string& prompt, T& input) {
	cout << prompt;

	if (!(cin >> input)) {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

// Global variables
int choice;
bool isRunning = true;
bool isLogged = false;
int choice;

int main() {
	BookService bookService;
void menuBookLoop() {
	while (isLogged) {
		displayBookMenu();
		getUserInput("Enter your choice (1-5): ", choice);

		switch (choice) {
		case 1: {
			cout << endl;
			displayBooks(bookService.getAll());
			break;
		}
		case 2: {
			bookService.create();
			break;
		}

		case 3: {
			displayBooks(bookService.getAll());
			cout << endl;
			bookService.updateById();
			break;
		}
			
		case 4: {
			displayBooks(bookService.getAll());
			cout << endl;
			bookService.deleteById();
			break;
		}
			
		case 5: {
			cout << "Exiting program...\n";
			isLogged = false;
			break;
		}

		default: {
			cout << "Invalid input. Please try again." << '\n';
		}
		}

		cout << endl;
	}

	return 0;
}