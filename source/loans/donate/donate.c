#include "donate.h"

void addBook(Book* book, const char* database) {
    FILE* file = openFile(database, "r+");

    if (file == NULL) {
        perror("Something is wrong while opening a file!");
    }

    int newBookId = getLastID(database);
    fseek(file, 0, SEEK_END);
    fprintf(file, "%d,%s,%s,%d\n",newBookId + 1, book->title, book->author, book->copies);

}