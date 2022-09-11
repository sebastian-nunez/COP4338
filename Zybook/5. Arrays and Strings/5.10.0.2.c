
#include <stdio.h>

int main(void) {
    char userStr[20] = "1234567890123456789"; // Input string
    int i;

    // Prompt user for string input
    printf("Enter string (<20 chars): ");
    scanf("%s", userStr);

    // Print string
    printf("\n%s\n", userStr);

    // Look for '@'
    for (i = 0; userStr[i] != '\0'; ++i) {
        if (userStr[i] == '@') {
            printf("Found '@'.\n");
        }
    }

    // The following is an ERROR.
    // May print chars it shouldn't.
    // Problem: doesn't stop at null char.
    printf("\n\"");            // Print opening "
    for (i = 0; i < 20; ++i) { // Print each char
        printf("%c", userStr[i]);
    }
    printf("\"\n"); // Print closing "

    // The following is an even WORSE ERROR.
    // Accesses beyond valid index range.
    // Program may crash.
    printf("\""); // Print opening "
    for (i = 0; i < 30; ++i) {
        printf("%c", userStr[i]); // Print each char
    }
    printf("\"\n"); // Print closing "

    return 0;
}
