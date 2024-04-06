#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../templates/templates.h"
#include "./register/register.h"
#include "./login/login.h"
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define BLUE    "\x1B[34m"
#define WHITE   "\x1B[37m"

int getAuthInput();
void authUser(int authInput, User *user);