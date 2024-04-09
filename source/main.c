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
    user = malloc(10 * sizeof(User));
    user->firstName = (char*) malloc(100 * sizeof(char));
    user->lastName = (char*) malloc(100 * sizeof(char));

    int authInput = getOption(1, 2);

    char auth = authUser(authInput, user);
    if (!auth) return 0;

    displayFunctionalities(user->firstName);

    int menuOption = getOption(1, 8);

    switch (menuOption) {

        case 1: {
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

        case 2: { // Return a book (reverse borrow)
            displayLoans(user, LOANS_DB);
            int loanId = getOption(1, 2);

            // get the number of books that the user wants to return
            int copies = getOption(1, 2);
        }

        case 3: { // Donate a book (basically append a new book)

            //Book* book;
            //book = malloc(sizeof(Book));
            //getBookDetails(book);
            //addBook(BOOKS_DB, book)
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
        case 8: { // Delete account (basically remove user from db)
            printf("Account deleted! Feel bad for losing you...");
            break;
        }
    }

    free(user);
}