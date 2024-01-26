// Include header files
#include "../include/UserInterface.h"
#include "../include/BookService.h"
#include "../include/AuthService.h"
#include "../include/MenuController.h"

// Variables
User currentUser;
bool isRunning = true;
bool isLogged = false;
int choice;

int main() {
	// Variables
	AuthService authService;
	BookService bookService;

	while (isRunning) {
		menuLoginLoop(authService);

		while (isLogged) {
			menuBookLoop(bookService);
		}
	}

	return 0;
}