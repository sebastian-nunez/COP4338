// Type a statement using srand() to seed random number generation using variable seedVal. Then type two statements using rand() to print two random integers between (and including) 0 and 9. End with a newline. Ex:
// 5
// 7

#include <stdio.h>
#include <stdlib.h>  // Enables use of rand()

int main(void) {
    int seedVal;

    scanf("%d", &seedVal);

    /* Your solution goes here  */
    srand(seedVal);
    printf("%d\n", rand() % 10);
    printf("%d\n", rand() % 10);

    return 0;
}
