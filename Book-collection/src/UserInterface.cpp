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
	cout << "3. Update Book\n";
	cout << "4. Delete Book\n";
	cout << "5. Exit\n\n";
}