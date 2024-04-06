#include "utils.h"

/**
 * Fool-proof function that lets user to select an option (x1, x2, .., xN)
 * @param int lowerLimit - First option in the list
 * @param int upperLimit - Last option in the list
 * @return The option chosen by the user
 */
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