#include "auth.h"

char authUser(int authInput, User *user) {

    // Get in account (Login)
    if (authInput == 1) {

        return signIn(user);

    }

    // Create a new account (Register)
    if (authInput == 2) {
        return createAccount(user);
    }
}