// Include header files
#include "../include/UserInterface.h"
#include "../include/BookService.h"
#include "../include/User.h"

// Global variables
int choice;
bool isLogged = false;
bool isRunning = true;

template<typename T>
void getUserInput(const string& prompt, T& input) {
	cout << prompt;

	if (!(cin >> input)) {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void menuBookLoop() {
	BookService bookService;
	cout << isLogged << endl;

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

void login() {
	Credentials credentials;
	getUserInput("Enter username: ", credentials.username);
	getUserInput("Enter password: ", credentials.password);

	UserRepository userRepository;
	for (User user : userRepository.getAll()) {
		if (user.getUsername() == credentials.username && user.getPassword() == credentials.password) {
			cout << "Logged in successfully!\n";
			isLogged = true;
			menuBookLoop();
		return;
		}
	}
	
	cout << "Invalid credentials. Please try again.\n";
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