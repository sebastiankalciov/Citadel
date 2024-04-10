#include "register.h"

char createAccount(User* user) {

    printf("%s", BLUE "Type first name: " RESET);
    scanf("%s", user->firstName);

    printf("%s", BLUE "Type last name: " RESET);
    scanf("%s", user->lastName);

    char* filePath = "../database/users.csv";
    char* userFound = strdup(findUser(filePath, user));

    if (strcmp(userFound, "NULL") != 0) {
        printf("You already have an account. You might want to sign in.");
        return 0;
    }
    user->userId = getLastID(filePath) + 1;
    addUser(filePath, user);
    return 1;

}

char createAccountFromConsole(User* user) {

    char* filePath = "../database/users.csv";
    char* userFound = strdup(findUser(filePath, user));

    if (strcmp(userFound, "NULL") != 0) {
        printf("You already have an account. You might want to sign in.");
        return 0;
    }

    addUser(filePath, user);
    return 1;

}
