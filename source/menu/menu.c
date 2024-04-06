// Define colors for text

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

#include "menu.h"
#include "../authentification/login/login.h"
#include "../authentification/register/register.h"

void displayHeader() {

    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s", RED   "--------------------------------CITADEL--------------------------------\n" RESET);
    printf("%s", WHITE "-----------------------Library Management System-----------------------\n" RESET);
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
}

void displayAuthOptions() {

    printf("%s", BLUE "Get started. Choose a method to get into the Citadel System\n" RESET);
    printf("%s", WHITE "1) Login\n" RESET);
    printf("%s", WHITE "2) Register\n" RESET);
    printf("%s", WHITE "TIP: You can use the commands directly in command line (login [name] [surname] / register [name] [surname])\n" RESET);
    printf("\n");
    printf("\n");
}

void displayFunctionalities(char* name) {

    printf("\n");
    printf("\n");
    printf(BLUE "Hello %s, what do you want to do today?\n", name);
    printf("%s", WHITE "1) Borrow - Borrow a book from the Citadel\n" RESET);
    printf("%s", WHITE "2) Return - Return a book that you borrowed\n" RESET);
    printf("%s", WHITE "3) Donate - Make a donation to the Citadel\n" RESET);
    printf("%s", WHITE "4) Loans - View your active loans\n" RESET);
    printf("%s", WHITE "4) Search - Search for a book in the Citadel by the title or author's name\n" RESET);
    printf("%s", WHITE "5) Log out\n" RESET);
    printf("%s", WHITE "6) Delete account (WARNING: You must not have any active loans in order to perform this action)\n" RESET);
}

void displayAvailableBooks() {
    printf("\n");
    printf("\n");
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s %s %s", WHITE "----------------------------", GREEN "BORROW SYSTEM", WHITE "----------------------------\n" RESET);
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s %s %s", WHITE "---------------------------", BLUE "Available books", WHITE "---------------------------\n" RESET);
    printf("-------Title----------Author--------Available copies-------------------\n");
    // TO-DO: While loop through the file to print every book
    printf("--1) DEMO BOOK 1   DEMO AUTHOR             1\n");
    printf("--2) DEMO BOOK 2   DEMO AUTHOR             2\n");
    printf("--3) DEMO BOOK 3   DEMO AUTHOR             3\n");
    printf("--4) DEMO BOOK 4   DEMO AUTHOR             4\n");
    printf("--5) Exit the menu\n");
}

void displayBorrowFunctionalities() {

}