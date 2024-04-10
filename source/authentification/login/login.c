#include "login.h"

char signIn(User* user) {

    printf("%s", BLUE "Type first name: " RESET);
    scanf("%s", user->firstName);

    printf("%s", BLUE "Type last name: " RESET);
    scanf("%s", user->lastName);

    char* filePath = "../database/users.csv";

    char* userFound = strdup(findUser(filePath, user));

    if (strcmp(userFound, "NULL") == 0) {
        printf("You do not have an account! You might want to create an account.");
        return 0;
    }
    return 1;

}

char signInFromConsole(User* user) {

    char* filePath = "../database/users.csv";

    char* userFound = strdup(findUser(filePath, user));

    if (strcmp(userFound, "NULL") == 0) {
        printf("You do not have an account! You might want to create an account.");
        return 0;
    }
    return 1;
}