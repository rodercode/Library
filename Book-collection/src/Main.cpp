// Include header files
#include "../include/UserInterface.h"
#include "../include/BookService.h"
#include "../include/User.h"

// Global variables
int choice;
bool isLogged = false;
bool isRunning = true;
BookService bookService;

template<typename T>
void getUserInput(const string& prompt, T& input) {
	cout << prompt;

	if (!(cin >> input)) {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void login() {
	string username, password;
	getUserInput("Enter username: ", username);
	getUserInput("Enter password: ", password);

	if (username != "admin" && password != "SimplePass") {
		cout << "Invalid username or password. Please try again." << '\n';
		return;
	}

	isLogged = true;
}



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
}

// Methods
void menuLoginLoop() {
	while (isRunning) {
		displayLoginMenu();
		getUserInput("Enter your choice (1-3): ", choice);

		switch (choice) {
		case 1: {
			cout << endl;
			login();
			menuBookLoop();
			break;
		}
		case 2: {
			cout << endl;
			cout << "Registering...\n";
			break;
		}

		case 3: {
			cout << endl;
			cout << "Exiting program...\n";
			isRunning = false;
			break;
		}
		}
	}

	cout << endl;
}

int main() {
	menuLoginLoop();
	return 0;
}