#pragma once

#include <stdlib.h>
#include <string.h>
#include "../../templates/templates.h"
#include "../files/utils.h"

char* findUser(const char* database, User* user);

void addUser(const char* database, User* user);
int getLastID(const char* database);
void deleteUser(User* user);