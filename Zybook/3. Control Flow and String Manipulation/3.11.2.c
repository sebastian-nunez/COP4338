// Write a switch statement that checks origLetter. If 'a' or 'A', print "Alpha". If 'b' or 'B', print "Beta". For any other character, print "Unknown". Use fall-through as appropriate. End with newline.

#include <stdio.h>

int main(void) {
    char origLetter;

    scanf(" %c", &origLetter);

    /* Your solution goes here  */
    switch (origLetter) {
        case 'a':
        case 'A':
            printf("Alpha\n");
            break;
        case 'b':
        case 'B':
            printf("Beta\n");
            break;
        default:
            printf("Unknown\n");
    }

    return 0;
}
