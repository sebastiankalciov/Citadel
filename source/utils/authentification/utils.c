#include "utils.h"

char* findUser(const char* database, User* user) {
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

        if (columnData != NULL && strcmp(columnData, user->firstName)) {
            printf("aiiic: %s\n", columnData);
            columnData = strtok(NULL, ",");
            if (columnData != NULL && strcmp(columnData, user->lastName) == 0) {
                printf("yessir\n");
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

    fprintf(file, "\n%d,%s,%s", getLastUserID(database) + 1, user->firstName, user->lastName);
    fclose(file);
}

int getLastUserID(const char* database) {
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
