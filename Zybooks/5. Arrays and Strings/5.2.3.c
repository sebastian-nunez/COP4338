// Write a for loop to print all elements in courseGrades, following each
// element with a space (including the last). Print forwards, then backwards.
// End each loop with a newline. Ex: If courseGrades = {7, 9, 11, 10}, print: 7
// 9 11 10 10 11 9 7

// Hint: Use two for loops. Second loop starts with i = NUM_VALS - 1. (Notes)

#include <stdio.h>

int main(void) {
    const int NUM_VALS = 4;
    int courseGrades[NUM_VALS];
    int i;

    for (i = 0; i < NUM_VALS; ++i) {
        scanf("%d", &(courseGrades[i]));
    }

    /* Your solution goes here  */
    for (int i = 0; i < 4; i++) printf("%d ", courseGrades[i]);

    printf("\n");

    for (int i = 3; i >= 0; i--) printf("%d ", courseGrades[i]);

    printf("\n");

    return 0;
}
