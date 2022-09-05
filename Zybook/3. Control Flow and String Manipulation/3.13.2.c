// Print the two strings, firstString and secondString, in alphabetical order. Assume the strings are lowercase. End with newline. Sample output:
// capes rabbits

#include <stdio.h>
#include <string.h>

int main(void) {
    char firstString[50];
    char secondString[50];

    scanf("%s", firstString);
    scanf("%s", secondString);

    /* Your solution goes here  */
    if (strcmp(firstString, secondString) < 0) {
        printf("%s %s\n", firstString, secondString);
    } else {
        printf("%s %s\n", secondString, firstString);
    }

    return 0;
}
