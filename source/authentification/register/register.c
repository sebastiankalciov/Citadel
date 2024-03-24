#include "register.h"

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define BLUE    "\x1B[34m"
#define WHITE   "\x1B[37m"

int getAuthInput() {

    int input = 0;
    printf("%s", "Choose: ");
    scanf("%d", &input);

    while (input != 1 && (input != 2)) {
        printf("%s", "Please choose a valid input: ");
        scanf("%d", &input);
    }

    return input;
}

void authUser(int authInput) {

    char firstName[100], lastName[100];

    // Get in account (Login)
    if (authInput == 1) {

        printf("%s", BLUE "Type first name: " RESET);
        scanf("%s", &firstName);

        printf("%s", BLUE "Type last name: " RESET);
        scanf("%s", &lastName);

        // TO-DO: Check if user has account


        // TO-DO: Display functionalities

    }

    // Create a new account (Register)
    if (authInput == 2) {

        printf("%s", BLUE "Type first name: " RESET);
        scanf("%s", &firstName);

        printf("%s", BLUE "Type last name: " RESET);
        scanf("%s", &lastName);

        // TO-DO: Check if user is already in DB


        // TO-DO: Add user in DB


        // TO-DO: Display functionalities
    }
}