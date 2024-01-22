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

void displayMenu() {
	cout << "Book Library Menu\n";
	cout << "1. Get All Books\n";
	cout << "2. Create Book\n";
	cout << "3. Delete Book\n";
	cout << "4. Exit\n\n";
	cout << "Enter your choice (1-4): ";
}

void getUserInput(int& choice) {
	cin >> choice;
}