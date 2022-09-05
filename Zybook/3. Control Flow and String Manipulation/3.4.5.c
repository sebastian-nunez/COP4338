// Write an if-else statement with multiple branches. If givenYear is 2101 or greater, print "Distant future" (without quotes). Else, if givenYear is 2001 or greater (2001-2100), print "21st century". Else, if givenYear is 1901 or greater (1901-2000), print "20th century". Else (1900 or earlier), print "Long ago". End with a newline. Remember that "\n" in a string literal starts a new line.

#include <stdio.h>

int main(void) {
    int givenYear;

    scanf("%d", &givenYear);

    /* Your solution goes here  */
    if (givenYear >= 2101) {
        printf("Distant future\n");
    } else if (givenYear >= 2001) {
        printf("21st century\n");
    } else if (givenYear >= 1901) {
        printf("20th century\n");
    } else {
        printf("Long ago\n");
    }

    return 0;
}
