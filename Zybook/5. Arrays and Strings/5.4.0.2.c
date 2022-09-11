// Iterating through an array for various purposes is an important programming
// skill to master. The program below computes the sum of an array's element
// values. For computing the sum, the program initializes a variable sum to 0,
// then simply adds the current iteration's array element value to that sum.

#include <stdio.h>

int main(void) {
    const int NUM_ELEMENTS = 8; // Number of elements
    int userVals[NUM_ELEMENTS]; // User numbers
    int i;                      // Loop index
    int sumVal;                 // For computing sum

    // Prompt user to populate array
    printf("Enter %d integer values...\n", NUM_ELEMENTS);

    for (i = 0; i < NUM_ELEMENTS; ++i) {
        printf("Value: ");
        scanf("%d", &(userVals[i]));
    }

    // Determine sum
    sumVal = 0;
    for (i = 0; i < NUM_ELEMENTS; ++i) {
        sumVal = sumVal + userVals[i];
    }

    printf("Sum: %d\n", sumVal);

    return 0;
}
