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
