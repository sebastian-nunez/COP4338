// Checking for proper number of command-line arguments.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Usage: program username userage */
int main(int argc, char *argv[]) {
    char nameStr[100]; // User name
    char ageStr[100];  // User age

    // Check if correct number of arguments provided
    if (argc != 3) {
        printf("Usage: myprog.exe name age\n");
        return 1; // 1 indicates error
    }

    // Grab inputs from command line
    strcpy(nameStr, argv[1]);
    strcpy(ageStr, argv[2]);

    // Output result
    printf("Hello %s. ", nameStr);
    printf("%s is a great age.\n", ageStr);

    return 0;
}
