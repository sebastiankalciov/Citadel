#include "auth.h"

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