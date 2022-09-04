// Compute the average kids per family. Note that the integers should be type cast to doubles.

#include <stdio.h>

int main(void) {
    int numKidsA;
    int numKidsB;
    int numKidsC;
    int numFamilies;
    double avgKids;

    scanf("%d", &numKidsA);
    scanf("%d", &numKidsB);
    scanf("%d", &numKidsC);
    scanf("%d", &numFamilies);

    /* Your solution goes here  */
    avgKids = (numKidsA + numKidsB + numKidsC) / (double)numFamilies;

    printf("%lf\n", avgKids);

    return 0;
}
