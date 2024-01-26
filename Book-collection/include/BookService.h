#pragma once
#include "BookRepository.h"
#include <iostream>
#include <vector>
#include "User.h"

using 
	std::vector,
	std::cin;

class BookService {

private:
	// Fields
	BookRepository* bookRepository;

public:
	// Constructor
	BookService();

	// Destructor
	~BookService();

	// CRUD Operations
	void create();
	Book getById();
	vector<Book>getAll();
	void updateById();
	void deleteById();
};