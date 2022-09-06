// Write a for loop to print all NUM_VALS elements of array hourlyTemp. Separate elements with a comma and space. Ex: If hourlyTemp = {90, 92, 94, 95}, print:
// 90, 92, 94, 95
// Your code's output should end with the last element, without a subsequent comma, space, or newline.

#include <stdio.h>

int main(void) {
    const int NUM_VALS = 4;
    int hourlyTemp[NUM_VALS];
    int i;

    for (i = 0; i < NUM_VALS; ++i) {
        scanf("%d", &(hourlyTemp[i]));
    }

    /* Your solution goes here  */
    for (int i = 0; i < NUM_VALS; i++) {
        if (i == NUM_VALS - 1) {
            printf("%d", hourlyTemp[i]);
            break;
        }

        printf("%d, ", hourlyTemp[i]);
    }

    printf("\n");

    return 0;
}
