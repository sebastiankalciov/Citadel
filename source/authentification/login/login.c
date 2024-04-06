#include "login.h"

void signIn(User *user) {

    printf("%s", BLUE "Type first name: " RESET);
    scanf("%s", user->firstName);

    printf("%s", BLUE "Type last name: " RESET);
    scanf("%s", user->lastName);

    // TO-DO: Check if user has account
    char userFound = findUser(user);

    if (!userFound) {
        printf("You do not have an account! You might want to create an account.");
        return;
    }



    // TO-DO: Display functionalities
}
