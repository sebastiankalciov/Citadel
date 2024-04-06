#pragma once

#include <stdlib.h>
#include <string.h>
#include "../../templates/templates.h"

char findUser(User* user);
char* getUser(User* user);

void addUser(User* user);
void deleteUser(User* user);