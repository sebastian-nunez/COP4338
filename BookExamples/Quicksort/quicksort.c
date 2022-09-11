#include <stdio.h>
#include <stdlib.h>

#include "constants.c"

void printArray(int array[], int size);
int ascendingOrder(const void *a, const void *b);
int decendingOrder(const void *a, const void *b);

int main() {
    printf("PI IMPORTED: %f\n", PI);
    int nums[5];
    for (int i = 0; i < 5; i++) {
        printf("Number %d :: ", i + 1);
        scanf("%d", &nums[i]);
    }

    printf("Unsorted Array: ");
    printArray(nums, 5);

    qsort(nums, 5, sizeof(int), ascendingOrder);
    printf("Sorted (ascending order) Array: ");
    printArray(nums, 5);

    qsort(nums, 5, sizeof(int), decendingOrder);
    printf("Sorted (decending order) Array: ");
    printArray(nums, 5);

    return 0;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    puts("");
}

int ascendingOrder(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int decendingOrder(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
