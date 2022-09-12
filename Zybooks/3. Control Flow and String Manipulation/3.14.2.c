// Write an expression to detect that the first character of userInput matches
// firstLetter.

#include <stdio.h>
#include <string.h>

int main(void) {
    char userInput[50];
    char firstLetter;

    scanf("%s", userInput);
    scanf(" %c", &firstLetter);

    if (/* Your solution goes here  */ userInput[0] == firstLetter) {
        printf("Found match: %c\n", firstLetter);
    } else {
        printf("No match: %c\n", firstLetter);
    }

    return 0;
}
