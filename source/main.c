#include "authentification/auth.h"
#include "menu/menu.h"
#include "./templates/templates.h"
#include <stdlib.h>
#include <string.h>

int main() {

    displayHeader();
    displayAuthOptions();

    User *user;
    user = malloc(sizeof(User));
    user->firstName = (char*)malloc(100*sizeof(char));
    user->lastName = (char*)malloc(100*sizeof(char));

    int authInput = getAuthInput();

    authUser(authInput, user);

    displayFunctionalities(user->firstName);
    free(user);
}