#include <stdlib.h>
#include <string.h>
#include "authentification/auth.h"
#include "menu/menu.h"
#include "utils/authentification/utils.h"
#include "loans/borrow/borrow.h"
#include "loans/return/return.h"
#include "loans/donate/donate.h"
#include "templates/templates.h"
#define USER_DB "../database/users.csv"
#define BOOKS_DB "../database/books.csv"
#define LOANS_DB "../database/loans.csv"
#define ADMINS_DB "../database/admins.csv"

int main(int argc, char *argv[]) {
    displayHeader();

    User *user;
    user = malloc(10 * sizeof(User));
    user->firstName = (char*) malloc(100 * sizeof(char));
    user->lastName = (char*) malloc(100 * sizeof(char));

    if (argc == 4) {

        char *command = argv[1];
        char *firstName = argv[2];
        char *lastName = argv[3];

        if (!isValidCommand(command)) {
            printf("Invalid command: %s\n", command);
            return 1;
        }
        int authInput;
        if (strcmp("login", command) == 0)
            authInput = 1;
        else
            authInput = 2;

        strcpy(user->firstName, firstName);
        strcpy(user->lastName, lastName);

        char auth = authUser(authInput, user, 1);
        if (!auth) return 0;

    } else {
        displayAuthOptions();
    }

    int authInput = getOption(1, 2);

    char auth = authUser(authInput, user, 2);
    if (!auth) return 0;

    displayFunctionalities(user->firstName);

    int menuOption = getOption(1, 7);

    switch (menuOption) {

        case 1: { // Borrow a book
            displayAvailableBooks(BOOKS_DB);

            int bookId = getOption(1, getLastID(BOOKS_DB));

            Book *newBook;
            newBook = malloc(10 * sizeof(Book));
            newBook->bookId = bookId;
            newBook->author = (char *) malloc(200 * sizeof(char));
            newBook->title = (char *) malloc(200 * sizeof(char));

            borrow(user, newBook);
            addLoan(user, newBook);

            printf("Book(s) borrowed succesfully!\n");
            free(newBook);
            break;

        }

        case 2: { // Return a book

            displayLoans(user, LOANS_DB);

            int loanId = getOption(1, 17);

            Book *book;
            book = malloc(10 * sizeof(Book));
            book->bookId = loanId;
            book->author = (char *) malloc(200 * sizeof(char));
            book->title = (char *) malloc(200 * sizeof(char));

            int copies = getOption(1, 30);

            returnBook(user, book, copies);

            // Does not work properly (I have to think how to put the offset such that it modifies the line)
            //removeLoan(user, book);

            printf("Book(s) returned succesfully!\n");

            free(book);
            break;

        }

        case 3: { // Donate a book

            Book* book;
            book = malloc(10 * sizeof(Book));
            book->author = (char *) malloc(200 * sizeof(char));
            book->title = (char *) malloc(200 * sizeof(char));

            getBookDetails(book);
            addBook(book, BOOKS_DB);

            printf("Book donated successfully! Thank you for your contribution!");

            break;
        }

        case 4: { // Display loans
            displayLoans(user, LOANS_DB);
            break;
        }

        case 5: { // Display books
            displayAvailableBooks(BOOKS_DB);
            break;
        }

        case 6: { // Search for a book (author/title)
            printf("Searching...");
            break;

        }
        case 7: { // Log out
            printf("Logging out...");
            break;

        }
    }

    free(user);
}