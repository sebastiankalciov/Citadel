#include "borrow.h"
#define BOOKS_DB "../database/books.csv"
#define LOANS_DB "../database/loans.csv"
void borrow(User* user, Book* book) {

    findBook(book,BOOKS_DB);

    printf("Below you will have to type the number of copies you want.\n");
    printf("If the number of copies you want is larger than the number of available copies, it will print an error.\n");

    int copies = getOption(1, book->copies);
    updateBookCopies(book, book->copies - copies);

    book->copies = copies;
}

void findBook(Book* book, char* database) {

    FILE* file = openFile(database, "r");
    if (file == NULL) {
        perror("Something is wrong while opening a file!");
    }

    char header[200];
    char data[400];
    char* row;

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        row = (char*) malloc(strlen(data) * sizeof(char) + 1);
        strcpy(row, data);

        char title[200], author[200];
        int id, copies;

        if (sscanf(data, "%d,%[^,],%[^,],%d", &id, title, author, &copies) == 4) {

            if (id == book->bookId){
                book->copies = copies;

                strcpy(book->title, title);
                strcpy(book->author, author);

                fclose(file);

                free(row);
                return;
            }
        }

    }

    fclose(file);
    free(row);
}

void addLoan(User* user, Book* book) {

    FILE* file = openFile(LOANS_DB, "r+");

    if (file == NULL) {
        perror("Something is wrong while opening a file!");
    }

    Loan loan;

    char* row;
    int loanExists = 0;

    char header[200], data[400];

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

        fseek(file, 0, SEEK_END);
        fprintf(file, "%d,%s,%s,%d\n", user->userId, book->title, book->author, book->copies);
        return;
    }

    // Move the cursor back at the beginning
    fseek(file, 0, SEEK_SET);

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        row = (char*) malloc(strlen(data) * sizeof(char) + 1);
        strcpy(row, data);

        if (sscanf(data, "%d,%[^,],%[^,],%d\n", &loan.userId, loan.title, loan.author, &loan.copies) == 4) {

            if (loan.userId == user->userId && strcmp(loan.title, book->title) == 0 &&
                strcmp(loan.author, book->author) == 0) {

                loan.copies += book->copies;

                fseek(file, -strlen(loan.title) - strlen(loan.author)- 6, SEEK_CUR);
                fprintf(file, "%d,%s,%s,%d\n", loan.userId, loan.title, loan.author, loan.copies);

                break;
            }

        }
    }
    fclose(file);
}

void updateBookCopies(Book* book, int copies) {
    FILE* file = openFile(BOOKS_DB, "r+");

    if (file == NULL) {
        perror("Something is wrong while opening a file!");
    }

    char header[200];
    char data[400];

    int bookId, currentCopies;
    char title[400], author[200];
    char* row;

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        row = (char*) malloc(strlen(data) * sizeof(char) + 1);
        strcpy(row, data);

        if (sscanf(data, "%d,%[^,],%[^,],%d\n", &bookId, title, author, &currentCopies) == 4) {

            if (book->bookId == bookId && strcmp(book->title, title) == 0 &&
                strcmp(book->author, author) == 0) {

                book->copies = copies;

                fseek(file, -strlen(book->title) - strlen(book->author)-8, SEEK_CUR);
                fprintf(file, "%d,%s,%s,%d\n", book->bookId, book->title, book->author, book->copies);

                break;
            }

        }
    }

    fclose(file);
}