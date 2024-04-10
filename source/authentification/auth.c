#include "auth.h"

char authUser(int authInput, User *user, int menu) {

    // Get in account (Login)


    if (menu == 1) {

        if (authInput == 1) {
            return signInFromConsole(user);
        }

        // Create a new account (Register)
        if (authInput == 2) {
            return createAccountFromConsole(user);
        }

    } else {

        if (authInput == 1) {
            return signIn(user);
        }

        // Create a new account (Register)
        if (authInput == 2) {
            return createAccount(user);
        }
    }
}