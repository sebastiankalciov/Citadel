#include "utils.h"

void readFromCSV(const char* filePath) {
    FILE* file = openFile(filePath, "r");
    if (file == NULL)
        return;

    char header[200];
    char data[200];

    fgets(header, 200, file);

    while (fgets(data, sizeof(data), file)) {

        char* columnData = strtok(data, ",");

        while (columnData != NULL) {
            printf("I have read: %s\n", columnData);
            columnData = strtok(NULL, ",");
        }
    }
    return;
}

FILE* openFile(const char* filePath, const char* mode) {

    if (filePath == NULL || strlen(filePath) == 0 ||
        mode == NULL || strlen(mode) == 0)
        return NULL;

    FILE* file = NULL;

    file = fopen(filePath, mode);

    return file;
}