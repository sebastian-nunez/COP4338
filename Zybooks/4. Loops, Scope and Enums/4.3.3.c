// Given positive integer numInsects, write a while loop that prints that number
// doubled without reaching 100. Follow each number with a space. After the
// loop, print a newline. Ex: If numInsects = 8, print: 8 16 32 64

#include <stdio.h>

int main(void) {
    int numInsects;

    scanf("%d", &numInsects);  // Must be >= 1

    /* Your solution goes here  */
    while (numInsects < 100) {
        printf("%d ", numInsects);
        numInsects *= 2;
    }

    printf("\n");

    return 0;
}
