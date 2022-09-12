// Write a function SwapArrayEnds() that swaps the first and last elements of
// the function's array parameter. Ex: sortArray = {10, 20, 30, 40} becomes {40,
// 20, 30, 10}.

#include <stdio.h>

/* Your solution goes here  */
void SwapArrayEnds(int arr[], int size) {
    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
}

int main(void) {
    const int SORT_ARR_SIZE = 4;
    int sortArray[SORT_ARR_SIZE];
    int i;
    int userNum;

    for (i = 0; i < SORT_ARR_SIZE; ++i) {
        scanf("%d", &sortArray[i]);
    }

    SwapArrayEnds(sortArray, SORT_ARR_SIZE);

    for (i = 0; i < SORT_ARR_SIZE; ++i) {
        printf("%d ", sortArray[i]);
    }
    printf("\n");

    return 0;
}
