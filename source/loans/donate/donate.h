#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../templates/templates.h"
#include "../../utils/utils.h"
#include "../../utils/authentification/utils.h"
#include "../borrow/borrow.h"

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define BLUE    "\x1B[34m"
#define WHITE   "\x1B[37m"

void addBook(Book* book, const char* database);