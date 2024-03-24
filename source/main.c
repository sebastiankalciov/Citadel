// include authentification system
#include <stdio.h>
#include "authentification/login/login.h"
#include "authentification/register/register.h"
#include "menu/menu.h"

int main() {
    displayHeader();
    displayAuthOptions();
    int authInput = getAuthInput();
    authUser(authInput);
    //displayFunctionalities();

}