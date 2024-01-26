#pragma once

#include "AuthService.h"
#include "BookService.h"
#include"UserInterface.h"

// Methods
void menuBookLoop(BookService& bookService);
void menuLoginLoop(AuthService& authService);