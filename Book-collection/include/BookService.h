#pragma once
#include "BookRepository.h"
#include <iostream>
#include <vector>

using 
	std::vector,
	std::cin;

class BookService {

private:
	// Fields
	BookRepository bookRepository;

public:
	// Constructor
	BookService();

	// CRUD Operations
	void create();
	Book getById();
	vector<Book>getAll();
	void updateById();
	void deleteById();
};