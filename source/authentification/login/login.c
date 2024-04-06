#include "login.h"

void signIn(User *user) {

    printf("%s", BLUE "Type first name: " RESET);
    scanf("%s", user->firstName);

    printf("%s", BLUE "Type last name: " RESET);
    scanf("%s", user->lastName);

    // TO-DO: Check if user has account


    // TO-DO: Display functionalities
}
