// Write a statement that assigns finalResult with the sum of num1 and num2,
// divided by 3. Ex: If num1 is 4 and num2 is 5, finalResult is 3.
#include <stdio.h>

int main(void) {
    int num1;
    int num2;
    int finalResult;

    scanf("%d", &num1);
    scanf("%d", &num2);

    /* Your solution goes here  */
    finalResult = (num1 + num2) / 3;

    printf("Final result: %d\n", finalResult);

    return 0;
}
