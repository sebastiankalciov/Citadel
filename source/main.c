#include "authentification/auth.h"
#include "menu/menu.h"
#include "utils/authentification/utils.h"
#include <stdlib.h>

#include <string.h>

int main() {

    displayHeader();
    displayAuthOptions();

    User *user;
    user = malloc(10*sizeof(User));
    user->firstName = (char*)malloc(100*sizeof(char));
    user->lastName = (char*)malloc(100*sizeof(char));

    int authInput = getOption(1, 2);

    char auth = authUser(authInput, user);
    if (!auth) return 0;

    displayFunctionalities(user->firstName);
    int menuOption = getOption(1, 6);

    displayAvailableBooks();
    //int bookOption = getOption(1, 5);

    free(user);
}