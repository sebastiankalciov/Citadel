#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../templates/templates.h"
#include "../../utils/authentification/utils.h"

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define BLUE    "\x1B[34m"
#define WHITE   "\x1B[37m"

void createAccount(User* user);