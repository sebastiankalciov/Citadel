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
}

void displayFunctionalities(char* name) {
    printf("\n");
    printf(BLUE "Hello %s, what do you want to do today?\n", name);
    printf("%s", WHITE "1) Borrow - Borrow a book from the Citadel\n" RESET);
    printf("%s", WHITE "2) Return - Return a book that you borrowed\n" RESET);
    printf("%s", WHITE "3) Donate - Make a donation to the Citadel\n" RESET);
    printf("%s", WHITE "4) Loans - View your active loans\n" RESET);
    printf("%s", WHITE "5) View books - Display all the books from the Citadel\n" RESET);
    printf("%s", WHITE "6) Search - Search for a book in the Citadel by the title or author's name\n" RESET);
    printf("%s", WHITE "7) Log out\n" RESET);
}

void displayAvailableBooks(const char* database) {
    printf("\n");
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s %s %s", WHITE "----------------------------", GREEN "BORROW SYSTEM", WHITE "----------------------------\n" RESET);
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s %s %s", WHITE "---------------------------", BLUE "Available books", WHITE "---------------------------\n" RESET);
    printf("%s| %-45s | %-35s | %s\n\n","Id", "Title", "Author", "Available copies");

    FILE* file = openFile(database, "r");
    if (file == NULL) {
        perror("[ERROR] Something is wrong while opening a file!");
    }
    char header[200];
    char data[200];

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        char title[200], author[200];
        int copies = 0, id;

        if (sscanf(data, "%d,%[^,],%[^,],%d", &id, title, author, &copies) == 4) {

            printf("%d | %-45s | %-35s | %d\n", id, title, author, copies);

        }

    }
}


void displayLoans(User* user, const char* database) {
    printf("\n");
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s %s %s", WHITE "----------------------------", GREEN "LOAN SYSTEM", WHITE "------------------------------\n" RESET);
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s %s %s %s", WHITE "------------------------", BLUE "Your loans,",user->firstName , WHITE "------------------------\n" RESET);
    printf("%-45s | %-35s | %s\n\n","Title", "Author", "Copies");


    FILE* file = openFile(database, "r");
    if (file == NULL) {
        perror("[ERROR] Something is wrong while opening a file!");
    }

    char header[200];
    char data[200];

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        char title[200], author[200];
        int copies = 0, id;

        if (sscanf(data, "%d,%[^,],%[^,],%d", &id, title, author, &copies) == 4) {
            if (id == user->userId)
                printf("%-45s | %-35s | %d\n",title, author, copies);

        }

    }
}

void getBookDetails(Book* book) {
    printf("\n");
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("%s %s %s", WHITE "----------------------------", GREEN "DONATION SYSTEM", WHITE "------------------------------\n" RESET);
    printf("%s", WHITE "-----------------------------------------------------------------------\n" RESET);
    printf("You will have to type below some details about the book you want to donate.\n");

    printf("Please type the name of the book: ");
    scanf("%s", book->title);

    printf("Please type the name of the author: ");
    scanf("%s", book->author);

    printf("Please type how many copies do you wish to donate: ");
    scanf("%d", &book->copies);

}