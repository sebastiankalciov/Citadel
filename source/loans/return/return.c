#include "return.h"
#define BOOKS_DB "../database/books.csv"
#define LOANS_DB "../database/loans.csv"

void returnBook(User* user, Book* book, int copies) {

    findBook(book,BOOKS_DB);

    updateBookCopies(book, book->copies + copies);
    book->copies = copies;

}

void removeLoan(User* user, Book* book) {

    FILE* file = openFile(LOANS_DB, "r+");

    if (file == NULL) {
        perror("Something is wrong while opening a file!");
    }

    Loan loan;

    int loanExists = 0;

    char header[200];
    char data[400];
    char* row;

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        row = (char*) malloc(strlen(data) * sizeof(char) + 1);
        strcpy(row, data);

        if (sscanf(data, "%d,%[^,],%[^,],%d", &loan.userId, loan.title, loan.author, &loan.copies) == 4) {

            if (loan.userId == user->userId && strcmp(loan.title, book->title) == 0 &&
                strcmp(loan.author, book->author) == 0) {
                loanExists = 1;
                break;
            }

        }
    }

    if (!loanExists) {
        return;
    }

    // Move the cursor back at the beginning
    fseek(file, 0, SEEK_SET);

    fgets(header, 200, file);
    long int linePosition = 0;

    while (fgets(data, sizeof(data), file)) {

        linePosition = ftell(file);

        if (sscanf(data, "%d,%[^,],%[^,],%d\n", &loan.userId, loan.title, loan.author, &loan.copies) == 4) {

            if (loan.userId == user->userId && strcmp(loan.title, book->title) == 0 &&
                strcmp(loan.author, book->author) == 0) {

                loan.copies -= book->copies;
                // problem here, i do not know how to put the offset
                fseek(file, linePosition, SEEK_SET);
                fprintf(file, "%d,%s,%s,%d\n", loan.userId, loan.title, loan.author, loan.copies);

                break;
            }

        }
    }
    fclose(file);
    free(row);
}


void getLoans(User* user, Loan* loan) {

    FILE* file = openFile(LOANS_DB, "r+");

    if (file == NULL) {
        perror("Something is wrong while opening a file!");
    }


    char header[200];
    char data[400];

    int loans = 0;
    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {


        if (sscanf(data, "%d,%[^,],%[^,],%d", &loan->userId, loan->title, loan->author, &loan->copies) == 4) {

            if (loan->userId == user->userId) {
                loans++;

            }

        }
    }

    loan->copies = loans;
    fclose(file);

}