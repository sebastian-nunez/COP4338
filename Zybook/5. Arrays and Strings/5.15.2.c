// zyDE 5.15.1: Validate domain names with arrays.
// Arrays are useful to process lists.

// A top-level domain (TLD) name is the last part of an Internet domain name like .com in example.com. A core generic top-level domain (core gTLD) is a TLD that is either .com, .net, .org, or .info. A restricted top-level domain is a TLD that is either .biz, .name, or .pro. A second-level domain is a single name that precedes a TLD as in apple in apple.com.

// The following program repeatedly prompts for a domain name, and indicates whether that domain name consists of a second-level domain followed by a core gTLD. Valid core gTLD's are stored in an array. For this program, a valid domain name must contain only one period, such as apple.com, but not support.apple.com. The program ends when the user enters -1.

// Run the program and enter domain names to validate.
// Extend the program to also recognize restricted TLDs using an array, and statements to validate against that array. The program should also report whether the TLD is a core gTLD or a restricted gTLD. Run the program again.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // Define the list of valid core gTLDs
    const int NUM_ELEMENTS_CORE = 4;
    const int MAX_SIZE = 6;
    const int NUM_ELEMENTS_RSTR = 3;

    char validCoreGtld[NUM_ELEMENTS_CORE][MAX_SIZE];
    char validRestrictedGtld[NUM_ELEMENTS_RSTR][MAX_SIZE];

    char inputName[50];
    char searchName[50];
    char theGtld[50];
    bool isValidDomainName;
    bool isCoreGtld;
    bool isRestrictedGtld;
    int periodCounter;
    int periodPosition;
    int i;

    i = 0;
    strcpy(validCoreGtld[i], ".com");
    ++i;
    strcpy(validCoreGtld[i], ".net");
    ++i;
    strcpy(validCoreGtld[i], ".org");
    ++i;
    strcpy(validCoreGtld[i], ".info");
    ++i;

    i = 0;
    strcpy(validRestrictedGtld[i], ".biz");
    ++i;
    strcpy(validRestrictedGtld[i], ".name");
    ++i;
    strcpy(validRestrictedGtld[i], ".pro");
    ++i;

    printf("\nEnter the next domain name (-1 to exit): \n");
    strcpy(inputName, "");
    scanf("%s", inputName);

    while (strcmp(inputName, "-1") != 0) {
        // Clear the string arrays of chars
        for (i = 0; i < 50; ++i) {
            searchName[i] = '\0';
            theGtld[i] = '\0';
        }

        for (i = 0; i < strlen(inputName); ++i) {
            searchName[i] = tolower(inputName[i]);
        }

        isValidDomainName = false;
        isCoreGtld = false;
        isRestrictedGtld = false;

        // Count the number of periods in the domain name
        periodCounter = 0;
        periodPosition = 0;

        for (i = 0; i < strlen(inputName); ++i) {
            if (searchName[i] == '.') {
                ++periodCounter;
                periodPosition = i;
            }
        }

        // If there is exactly one period that is not at the start
        // or end of searchName, check if the TLD is a core gTLD or a restricted gTLD
        if ((periodCounter == 1) && (searchName[0] != '.') &&
            (searchName[strlen(searchName) - 1] != '.')) {
            isValidDomainName = true;
        }

        if (isValidDomainName) {
            // Extract the Top-level Domain name starting at the period's position.
            // Ex: If searchName = "example.com", the next statement extracts ".com"
            for (i = periodPosition; i < strlen(searchName); ++i) {
                theGtld[i - periodPosition] = searchName[i];
            }

            i = 0;
            while ((i < NUM_ELEMENTS_CORE) && (!isCoreGtld)) {
                if (strcmp(theGtld, validCoreGtld[i]) == 0) {
                    isCoreGtld = true;
                } else {
                    ++i;
                }
            }

            i = 0;
            while ((i < NUM_ELEMENTS_RSTR) && (!isRestrictedGtld)) {
                if (strcmp(theGtld, validRestrictedGtld[i]) == 0) {
                    isRestrictedGtld = true;
                } else {
                    ++i;
                }
            }
        }

        printf("\"%s\" ", inputName);
        if (isValidDomainName) {
            printf("is a valid domain name and ");
            if (isCoreGtld) {
                printf("has a core gTLD of \"%s\".\n", theGtld);
            } else if (isRestrictedGtld) {
                printf("has a restricted gTLD of \"%s\".\n", theGtld);
            } else {
                printf("does not have a core or restricted gTLD.\n");
            }
        } else {
            printf("is not a valid domain name.\n");
        }

        printf("\nEnter the next domain name (-1 to exit): \n");
        strcpy(inputName, "");
        scanf("%s", inputName);
    }

    return 0;
}
