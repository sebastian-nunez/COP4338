// Set hasDigit to true if the 3-character passCode contains a digit.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    bool hasDigit;
    char passCode[50];

    hasDigit = false;
    scanf("%s", passCode);

    /* Your solution goes here  */
    hasDigit = isdigit(passCode[0]) || isdigit(passCode[1]) || isdigit(passCode[2]);

    if (hasDigit) {
        printf("Has a digit.\n");
    } else {
        printf("Has no digit.\n");
    }

    return 0;
}
