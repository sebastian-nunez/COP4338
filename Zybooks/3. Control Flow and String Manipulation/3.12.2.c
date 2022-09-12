// Write an if-else statement to describe an integer. Print "Positive even
// number" if isEven and isPositive are both true. Print "Positive number" if
// isEven is false and isPositive is true. Print "Not a positive number"
// otherwise. End with newline.

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int userNum;
    bool isPositive;
    bool isEven;

    scanf("%d", &userNum);
    isPositive = (userNum > 0);
    isEven = ((userNum % 2) == 0);

    /* Your solution goes here  */
    if (isEven && isPositive) {
        printf("Positive even number\n");
    } else if (!isEven && isPositive) {
        printf("Positive number\n");
    } else {
        printf("Not a positive number\n");
    }

    return 0;
}
