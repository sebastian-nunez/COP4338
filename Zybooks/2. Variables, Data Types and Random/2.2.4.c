// Write a statement that increases numPeople by 5. If numPeople is initially
// 10, then numPeople becomes 15.

#include <stdio.h>

int main(void) {
    int numPeople;

    scanf("%d", &numPeople);

    /* Your solution goes here  */
    numPeople = numPeople + 5;

    printf("There are %d people.\n", numPeople);

    return 0;
}
