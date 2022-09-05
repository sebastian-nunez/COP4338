// zyDE 4.14.1: Validate domain names.
// A top-level domain (TLD) name is the last part of an Internet domain name like .com in example.com. A core generic top-level domain (core gTLD) is a TLD that is either .com, .net, .org, or .info. A second-level domain is a single name that precedes a TLD as in apple in apple.com

// The following program uses a loop to repeatedly prompt for a domain name, and indicates whether that domain name consists of a second-level domain followed by a core gTLD. An example of a valid domain name for this program is apple.com. An invalid domain name for this program is support.apple.com because the name contains two periods. The program ends when the user presses just the Enter key in response to a prompt.

// Run the program and enter domain names to validate. Note that even valid input is flagged as invalid.
// Change the program to validate a domain name. A valid domain name for this program has a second-level domain followed by a core gTLD. Run the program again.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char coreGtld1[50];
    char coreGtld2[50];
    char coreGtld3[50];
    char coreGtld4[50];
    char inputName[50];
    char searchName[50];
    char theTld[50];
    bool isCoreGtld;
    int periodCounter;
    int periodPosition;
    int j;
    int i;

    strcpy(coreGtld1, ".com");
    strcpy(coreGtld2, ".net");
    strcpy(coreGtld3, ".org");
    strcpy(coreGtld4, ".info");
    // strcpy(theTld, "");
    isCoreGtld = false;
    periodPosition = 0;

    printf("\nEnter the next domain name (<Enter> to exit): \n");
    strcpy(inputName, "");
    scanf("%s", inputName);

    while (strlen(inputName) != 0) {
        for (j = 0; j < 50; ++j) {
            searchName[j] = tolower(inputName[j]);
        }
        isCoreGtld = false;

        periodCounter = 0;
        for (i = 0; i < 50; ++i) {
            if (searchName[i] == '.') {
                periodCounter++;
                periodPosition = i;
            }
        }

        if ((periodCounter == 1) && (searchName[0] != '.')) {
            // Extract the top-level domain name starting at the period's position.
            // Ex: If searchName = "example.com", the next statement extracts ".com"
            for (j = periodPosition; j < 50; ++j) {
                theTld[j - periodPosition] = searchName[j];
            }

            if (strcmp(theTld, coreGtld1) == 0) {
                isCoreGtld = true;
            } else if (strcmp(theTld, coreGtld2) == 0) {
                isCoreGtld = true;
            } else if (strcmp(theTld, coreGtld3) == 0) {
                isCoreGtld = true;
            } else if (strcmp(theTld, coreGtld4) == 0) {
                isCoreGtld = true;
            } else {
                isCoreGtld = false;
            }
        }

        printf("\"%s\" ", inputName);
        if (isCoreGtld) {
            printf("is a second-level domain followed by a core gTLD \"%s\".\n", theTld);
        } else {
            printf("is not a second-level domain followed by a core gTLD.\n");
        }

        printf("\nEnter the next domain name (or <Enter> to exit): \n");
        strcpy(inputName, "");
        scanf("%s", inputName);
    }

    return 0;
}
