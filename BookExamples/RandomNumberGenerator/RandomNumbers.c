#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000
#define LOWER 2
#define UPPER 5
#define RANGE 3

int randInt(int lower, int upper);

int main() {
    int randNum;
    int randDist[RANGE] = {0};
    srand(time(NULL));

    for (int i = LOWER; i < MAX_ITERATIONS; i++) {
        randNum = randInt(LOWER, UPPER);
        randDist[randNum - LOWER]++;
    }

    int sum = 0;
    for (int i = LOWER; i < RANGE; i++) {
        int count = randDist[i];
        sum += count;

        printf("The number %d, occured: %d times\n", i + LOWER, count);
    }

    printf("\nThe total number of occurences: %d\n", sum);

    return 0;
}

int randInt(int lower, int upper) { return (rand() % upper) + lower; }
