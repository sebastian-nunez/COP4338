// Write a loop that sets newScores to oldScores shifted once left, with element
// 0 copied to the end. Ex: If oldScores = {10, 20, 30, 40}, then newScores =
// {20, 30, 40, 10}.

#include <stdio.h>
/*


 */
int main(void) {
    const int SCORES_SIZE = 4;
    int oldScores[SCORES_SIZE];
    int newScores[SCORES_SIZE];
    int i;

    for (i = 0; i < SCORES_SIZE; ++i) {
        scanf("%d", &(oldScores[i]));
    }

    /* Your solution goes here  */
    for (int i = 0; i < SCORES_SIZE; i++) {
        int curr = oldScores[i];

        if (i == 0) {
            newScores[SCORES_SIZE - 1] = curr;
        } else {
            newScores[i - 1] = curr;
        }
    }

    for (i = 0; i < SCORES_SIZE; ++i) {
        printf("%d ", newScores[i]);
    }
    printf("\n");

    return 0;
}
