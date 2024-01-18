#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using
std::cout,
std::cin,
std::string,
std::vector,
std::fstream,
std::istringstream,
std::setw,
std::ios;

// Class Book
class Book {
private:
	// Fields
	int bookId;
	string title, author;
	bool borrowed;

public:

	Book(int bookId, string title, string author, bool borrowed)
		: bookId(bookId), title(title), author(author), borrowed(borrowed) {}

	int getBookId(){
		return bookId;
	}
		
	// Setters
	void isBorrowed(bool borrowed) {
		this->borrowed = borrowed;
	}

	// Getters
	string getTitle() {
		return title;
	}

	string getAuthor() {
		return author;
	}

	bool getBorrowed() {
		return borrowed;
	}
};

class Person {
private:
	// Fields
	string username, password;

public:
	// Constructor
	Person(string username, string password)
		:username(username), password(password) {}
};

// Class User
class User {
private:
	// Fields
	string username;

public:
	// Constructor
	User(string username) 
		:username(username) {}
	
	// Methods
	void returnBook(Book book) {
		book.isBorrowed(false);
	}

	void borrowBook(Book book) {
		book.isBorrowed(true);
	}
};

// Class Library
class Library {
private:
	// Fields
	fstream file;
	string filePath;

public:
	// Constructor
	Library(): filePath("database/book.csv") {}

	// Methods
	void addBook(Book& book){
		file.open(filePath, ios::out | ios::app);
		if (!file.is_open())
		{
			cout << "File not found: " << filePath << '\n';
			exit(1);
		}

		file << book.getTitle() << ", "
			 << book.getAuthor() << ", "
			<< book.getBorrowed() << '\n';

		file.close();
	}

	vector<Book> getBooks() {
		// Open book.txt file
		 file.open(filePath, ios::in);

		 // Check if book.txt file is open
		if (!file.is_open()) {
			cout << "File not found: " << filePath << '\n';
			exit(1);
		}

		string book;
		vector<Book> books;

		while (getline(file, book)) {
			istringstream iss(book);
			string idStr, title, author, borrowedStr;

			getline(iss, idStr, ',');
			getline(iss, title, ',');
			getline(iss, author, ',');
			getline(iss, borrowedStr, ',');

			int bookId = stoi(idStr);
			bool borrowed = 0;

			if (borrowedStr == "1") {
				borrowed = 1;
			}

			// add a book object to vector
			books.push_back(Book(bookId, title, author, borrowed));
		}

		// Close book.txt file
		file.close();

		return books;
	}
};


// UserInterface methods
void displayLoginMenu() {
	cout << "1. Login\n";
	cout << "2. Register\n";
	cout << "3. Exit\n";
	cout << "Enter your choice: ";
}


void displayBookMenu() {
	cout << '\n';
	cout << "Welcome to the Library\n";
	cout << "1. Display available books\n";
	cout << "2. Display your books\n";
	cout << "3. Return a book\n";
	cout << "4. Exit\n";
	cout << "Enter your choice: ";
}

void displayBooks(const vector<Book>& books) {
	cout << '\n';
	
	// table header
	cout << std::left <<
		setw(5) << "Id" <<
		setw(25) << "Title" <<
		setw(25) << "Author" <<
		setw(25) << "Available" <<
		'\n';
	cout << string(65, '-') << '\n';

	// table body
	for (Book book : books) {
		cout << std::left <<
			setw(5) << book.getBookId() <<
			setw(25) << book.getTitle() <<
			setw(25) << book.getAuthor() <<
			setw(25) << (book.getBorrowed() ? "Yes" : "No") <<
			'\n';
	}
}

void displayBook() {
	cout << '\n';
	cout << std::left <<setw(5) << "Book" << '\n';
	cout << string(30, '-') << '\n';
	cout << "ID: " << 1 << '\n';
	cout << "Title: " << "The Greate Gatsby" << '\n';
	cout << "Author: " << "F.Scott Fitzgerald" << '\n';
	cout << "Available: " << "Yes" << '\n';
}

void printMessage(const string& message) {
	cout << message << '\n';
}

void nextLine() {
	cout << '\n';
}

void getUserInput(int& input) {
	cin >> input;
}

bool isRunning = true;
	
// Main
int main() {
	Library library;
	int choice;

	while (isRunning) {
		displayBookMenu();
		getUserInput(choice);

		switch (choice){
		case 1:
			displayBooks(library.getBooks());
			cout << "\nSelect a book by its id: ";
			getUserInput(choice);
			displayBook();
			cout << "\n[1] Borrow [2] Go back";
			break;
		case 2:
			printMessage("Borrow a book\n");
			break;
		case 3:
			printMessage("Return a book\n");	
			break;
		case 4:
			printMessage("Exiting...\n");
			isRunning = false;
			break;
		default:
			printMessage("Invalid choice\n");
			break;
		}
	}

	return 0;
}

