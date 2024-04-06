#include "register.h"

void createAccount(User *user) {

    printf("%s", BLUE "Type first name: " RESET);
    scanf("%s", user->firstName);

    printf("%s", BLUE "Type last name: " RESET);
    scanf("%s", user->lastName);

    // TO-DO: Check if user is already in DB
    int userFound = findUser(user);

    // TO-DO: Add user in DB


    // TO-DO: Display functionalities
}
