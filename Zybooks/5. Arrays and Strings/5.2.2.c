// Write three statements to print the first three elements of array runTimes.
// Follow each statement with a newline. Ex: If runTimes[5] = {800, 775, 790,
// 805, 808}, print: 800 775 790

#include <stdio.h>

int main(void) {
    const int NUM_ELEMENTS = 5;
    int runTimes[NUM_ELEMENTS];
    int i;

    for (i = 0; i < NUM_ELEMENTS; ++i) {
        scanf("%d", &(runTimes[i]));
    }

    /* Your solution goes here  */
    printf("%d\n", runTimes[0]);
    printf("%d\n", runTimes[1]);
    printf("%d\n", runTimes[2]);

    return 0;
}
