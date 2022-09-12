// Type two statements that use rand() to print 2 random integers between (and
// including) 100 and 149. End with a newline. Ex: 101 133

#include <stdio.h>
#include <stdlib.h>  // Enables use of rand()
#include <time.h>    // Enables use of time()

int main(void) {
    int seedVal;

    scanf("%d", &seedVal);
    srand(seedVal);

    /* Your solution goes here  */
    printf("%d\n", (rand() % 50) + 100);
    printf("%d\n", (rand() % 50) + 100);

    return 0;
}
