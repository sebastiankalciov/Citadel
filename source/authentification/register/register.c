#include "register.h"

char createAccount(User* user) {

    printf("%s", BLUE "Type first name: " RESET);
    scanf("%s", user->firstName);

    printf("%s", BLUE "Type last name: " RESET);
    scanf("%s", user->lastName);

    // TO-DO: Check if user is already in DB
    char* filePath = "../database/users.csv";
    char* userFound = strdup(findUser(filePath, user));

    if (strcmp(userFound, "NULL") != 0) {
        printf("You already have an account. You might want to sign in.");
        return 0;
    }

    addUser(filePath, user);
    return 1;

}
