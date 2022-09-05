// zyDE 3.20.1: Search for name using branches.
// A core generic top-level domain (core gTLD) name is one of the following Internet domains: .com, .net, .org, and .info (ICANN: gTLDs). The following program asks the user to input a name and prints whether that name is a gTLD. The program uses the strcmp() function, which returns zero if the two compared strings are identical.

// Run the program, noting that the .info input name is not currently recognized as a gTLD.
// Extend the if-else statement to detect the .info domain name as a gTLD. Run the program again.
// Extend the program to output a message if the user entered the name without a leading dot. Ex:"com" does not start with a dot.

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char inputName[50];
    char searchName[50];
    char coreGtld1[50];
    char coreGtld2[50];
    char coreGtld3[50];
    char coreGtld4[50];
    bool isCoreGtld;

    strcpy(coreGtld1, ".com");
    strcpy(coreGtld2, ".net");
    strcpy(coreGtld3, ".org");
    strcpy(coreGtld4, ".info");
    isCoreGtld = false;

    printf("\nEnter a top-level domain name: \n");
    scanf("%s", inputName);

    // If the user entered a name without a leading dot,
    // print an error message.
    if (inputName[0] != '.') {
        printf("\"%s\" does not start with a dot.\n", inputName);
    } else {
        strcpy(searchName, inputName);

        // Determine whether the user-entered name is a gTLD
        if (strcmp(searchName, coreGtld1) == 0) {
            isCoreGtld = true;
        } else if (strcmp(searchName, coreGtld2) == 0) {
            isCoreGtld = true;
        } else if (strcmp(searchName, coreGtld3) == 0) {
            isCoreGtld = true;
        } else if (strcmp(searchName, coreGtld4) == 0) {
            isCoreGtld = true;
        } else {
            isCoreGtld = false;
        }

        printf("The name \"%s\" ", inputName);
        if (isCoreGtld) {
            printf("is a core gTLD.\n");
        } else {
            printf("is not a core gTLD.\n");
        }
    }

    return 0;
}
