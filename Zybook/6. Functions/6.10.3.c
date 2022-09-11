// Define a function SwapRank() that takes two char parameters passed by pointer
// and swaps the values in the two parameters. The function does not return any
// value.

// Ex: If the input is B A, then the output is:

// A B

#include <stdio.h>

/* Your code goes here */
void SwapRank(char *rank1, char *rank2) {
    char temp = *rank1;
    *rank1 = *rank2;
    *rank2 = temp;
}

int main(void) {
    char rank1;
    char rank2;

    scanf(" %c", &rank1);
    scanf(" %c", &rank2);

    SwapRank(&rank1, &rank2);

    printf("%c %c\n", rank1, rank2);

    return 0;
}
