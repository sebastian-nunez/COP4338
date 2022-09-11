// Write a loop that subtracts 1 from each element in lowerScores. If the
// element was already 0 or negative, assign 0 to the element. Ex: lowerScores =
// {5, 0, 2, -3} becomes {4, 0, 1, 0}.

#include <stdio.h>

int main(void) {
    const int SCORES_SIZE = 4;
    int lowerScores[SCORES_SIZE];
    int i;

    for (i = 0; i < SCORES_SIZE; ++i) {
        scanf("%d", &(lowerScores[i]));
    }

    /* Your solution goes here  */
    for (int i = 0; i < SCORES_SIZE; i++) {
        lowerScores[i]--;
        if (lowerScores[i] < 0) {
            lowerScores[i] = 0;
        }
    }

    for (i = 0; i < SCORES_SIZE; ++i) {
        printf("%d ", lowerScores[i]);
    }
    printf("\n");

    return 0;
}
