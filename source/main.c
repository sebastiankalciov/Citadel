#include <stdlib.h>
#include <string.h>
#include "authentification/auth.h"
#include "menu/menu.h"
#include "utils/authentification/utils.h"
#include "loans/borrow/borrow.h"
#include "templates/templates.h"
#define USER_DB "../database/users.csv"
#define BOOKS_DB "../database/books.csv"
#define LOANS_DB "../database/loans.csv"
#define ADMINS_DB "../database/admins.csv"

int main() {

    displayHeader();
    displayAuthOptions();

    User *user;
    user = malloc(10*sizeof(User));
    user->firstName = (char*)malloc(100*sizeof(char));
    user->lastName = (char*)malloc(100*sizeof(char));

    int authInput = getOption(1, 2);

    char auth = authUser(authInput, user);
    if (!auth) return 0;

    displayFunctionalities(user->firstName);

    int menuOption = getOption(1, 6);

    switch (menuOption) {
        case 1: {
            displayAvailableBooks(BOOKS_DB);
            int bookId = getOption(1, getLastID(BOOKS_DB));
            //borrow(user, bookId);
        }

        case 2: { // return a book
            displayLoans(user);
            int loanId = getOption(1, 2);

            // get the number of books that the user wants to return
            int copies = getOption(1, 2);
        }

        case 3: {
            break;
            //Book *book;
            //book = malloc(sizeof(Book));
            //getBookDetails(book);
            //addBook(BOOKS_DB, book)

        }

        case 4: { // return a book
            printf("al doile meniu ai mancamiai");
        }

        case 5: { // return a book
            printf("al doile meniu ai mancamiai");
        }

        case 6: { // return a book
            printf("al doile meniu ai mancamiai");

        }
    }

    free(user);
}