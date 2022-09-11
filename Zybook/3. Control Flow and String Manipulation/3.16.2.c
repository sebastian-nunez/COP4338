// Create a conditional expression that evaluates to string "negative" if
// userVal is less than 0, and "non-negative" otherwise. Ex: If userVal is -9,
// output is: -9 is negative.

#include <stdio.h>
#include <string.h>

int main(void) {
    char condStr[50];
    int userVal;

    scanf("%d", &userVal);

    strcpy(condStr, /* Your solution goes here  */ (userVal < 0)
                        ? "negative"
                        : "non-negative");

    printf("%d is %s.\n", userVal, condStr);

    return 0;
}
