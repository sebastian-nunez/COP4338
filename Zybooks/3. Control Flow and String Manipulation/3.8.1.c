// Re-type the code and fix any errors. The code should convert non-positive
// numbers to 1. if (userNum > 0)
//    printf("Positive.\n");
// else
//    printf("Non-positive, converting to 1.\n");
//    userNum = 1;

// printf("Final: %d\n", userNum);

#include <stdio.h>

int main(void) {
    int userNum;

    scanf("%d", &userNum);

    /* Your solution goes here  */
    if (userNum > 0)
        printf("Positive.\n");
    else {
        printf("Non-positive, converting to 1.\n");
        userNum = 1;
    }

    printf("Final: %d\n", userNum);

    return 0;
}
