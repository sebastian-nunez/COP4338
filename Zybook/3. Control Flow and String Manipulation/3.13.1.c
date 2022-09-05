// Write an if-else statement that prints "Goodbye" if userString is "Quit", else prints "Hello". End with newline.

#include <stdio.h>
#include <string.h>

int main(void) {
    char userString[50];

    scanf("%s", userString);

    /* Your solution goes here  */
    if (strcmp(userString, "Quit") == 0) {
        printf("Goodbye\n");

    } else {
        printf("Hello\n");
    }

    return 0;
}
