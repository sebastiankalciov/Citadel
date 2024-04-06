#include "register.h"

void createAccount(User* user) {

    printf("%s", BLUE "Type first name: " RESET);
    scanf("%s", user->firstName);

    printf("%s", BLUE "Type last name: " RESET);
    scanf("%s", user->lastName);

    // TO-DO: Check if user is already in DB
    char userFound = findUser(user);

    if (userFound) {
        printf("You already have an account! You might want to log in instead of creating a new account");
        return;
    }

    // TO-DO: Add user in DB
    addUser(user);
}
