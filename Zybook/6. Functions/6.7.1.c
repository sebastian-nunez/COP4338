// Add two more statements to main() to test inputs 3 and -1. Use print
// statements similar to the existing one (don't use assert).

#include <stdio.h>

// Function returns origNum cubed
int CubeNum(int origNum) { return origNum * origNum * origNum; }

int main(void) {
    printf("Testing started\n");

    printf("2: Expecting 8, got: %d\n", CubeNum(2));

    /* Your solution goes here  */
    printf("3: Expecting 27, got: %d\n", CubeNum(3));
    printf("-1: Expecting -1, got: %d\n", CubeNum(-1));

    printf("Testing completed\n");

    return 0;
}
