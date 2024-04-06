#include "utils.h"

int getOption(int lowerLimit, int upperLimit) {
    char input[256];
    printf("%s", "Please choose an option: ");
    scanf("%255s", input);
    int option;
    while (1){
        option = atoi(input);
        if (option >= lowerLimit && option <= upperLimit)
            return option;

        printf("%s", "Please choose a valid input: ");
        scanf("%255s", input);

    }

}