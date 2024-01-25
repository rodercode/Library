#include "../include/UserInterface.h"


void displayBooks(vector<Book> books) {
	cout << "Book Collection" << endl;

	for (Book book : books) {
		cout << "--------------------------\n";
		cout << "Id: " << book.getBookId() << "\n";
		cout << "Title: " << book.getTitle() << "\n";
		cout << "Author: " << book.getAuthor() << "\n";
		cout << "Genre: " << book.getGenreName() << "\n";
	}

}

void displayBookMenu() {
	cout << "Book Library Menu\n";
	cout << "1. Get All Books\n";
	cout << "2. Create Book\n";
	cout << "3. Update Book\n";
	cout << "4. Delete Book\n";
	cout << "5. Logout\n\n";
}

void displayLoginMenu() {
	cout << "1. Login to the system\n";
	cout << "2. Registrate new account\n";
	cout << "3. Exit \n";
}