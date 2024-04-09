#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "../templates/templates.h"

void displayHeader();
void displayAuthOptions();
void displayFunctionalities(char* name);

void displayAvailableBooks(const char* database);

void displayLoans(User* user, const char* database);

void getBookDetails();