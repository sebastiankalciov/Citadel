#include "utils.h"

char* findUser(const char* database, User* user) {
    FILE* file = openFile(database, "r");
    if (file == NULL) {
        perror("[ERROR] Something is wrong while opening a file!");
    }

    char header[200];
    char data[200];
    char* row;

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        row = (char*)malloc(strlen(data) * sizeof(char) + 1);
        strcpy(row, data);

        char firstName[200], lastName[200];
        if (sscanf(data, "%*d,%[^,],%s", firstName, lastName) == 2) {

            if (strcmp(firstName, user->firstName) == 0 && strcmp(lastName, user->lastName) == 0){

                fclose(file);
                return row;
            }
        }

    }
    fclose(file);
    return "NULL";
}


void addUser(const char* database, User* user) {
    if (user == NULL)
        return;

    FILE* file = openFile(database, "a");

    if (file == NULL)
        return;

    fprintf(file, "\n%d,%s,%s", getLastID(database) + 1, user->firstName, user->lastName);
    fclose(file);
}

int getLastID(const char* database) {
    FILE* file = openFile(database, "r");

    char header[200];
    char data[200];
    char* columnData;
    char* row;

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        row = (char*)malloc(strlen(data) * sizeof(char) + 1);
        strcpy(row, data);
        columnData = strtok(data, ",");
    }
    return atoi(columnData);
}

void deleteUser(User* user) {

}
