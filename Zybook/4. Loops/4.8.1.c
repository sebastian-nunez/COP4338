// Print numbers 0, 1, 2, ..., userNum as shown, with each number indented by that number of spaces. For each printed line, print the leading spaces, then the number, and then a newline. Hint: Use i and j as loop variables (initialize i and j explicitly). Note: Avoid any other spaces like spaces after the printed number. Ex: userNum = 3 prints:
// 0
//  1
//   2
//    3

#include <stdio.h>

int main(void) {
    int userNum;
    int i;
    int j;

    scanf("%d", &userNum);

    /* Your solution goes here  */
    for (int i = 0; i <= userNum; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("%d\n", i);
    }

    return 0;
}
