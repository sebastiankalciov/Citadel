#include "authentification/auth.h"
#include "menu/menu.h"
#include "utils/files/utils.h"
#include <stdlib.h>

#include <string.h>

int main() {

    displayHeader();
    displayAuthOptions();

    User *user;
    user = malloc(sizeof(User));
    user->firstName = (char*)malloc(100*sizeof(char));
    user->lastName = (char*)malloc(100*sizeof(char));

    int authInput = getOption(1, 2);

    authUser(authInput, user);

    displayFunctionalities(user->firstName);
    int menuOption = getOption(1, 6);

    printf("Option selected: %d", menuOption);
    displayAvailableBooks();
    int bookOption = getOption(1, 5);
    //char* filePath = "../database/users.csv";
    //readFromCSV(filePath);
    free(user);
}