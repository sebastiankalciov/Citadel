#include "auth.h"

int getAuthInput() {

    int input = 0;
    printf("%s", "Choose: ");
    scanf("%d", &input);

    while (input != 1 && input != 2){
        printf("%s", "Please choose a valid input: ");
        scanf("%d", &input);
    }

    return input;
}

void authUser(int authInput, User *user) {


    // Get in account (Login)
    if (authInput == 1) {

        signIn(user);

    }

    // Create a new account (Register)
    if (authInput == 2) {
        createAccount(user);
    }
}