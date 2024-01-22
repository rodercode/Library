#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "../include/Book.h"

using
std::cout,
std::cin,
std::endl,
std::string,
std::vector,
std::istringstream,
std::ios;

class BookService {
private:
		BookRepository bookRepository;

public:
	BookService(){}

	vector<Book>getAll() {
		return bookRepository.getAll();
	}
};

bool isRunning = true;

// Main
int main() {
	return 0;
}