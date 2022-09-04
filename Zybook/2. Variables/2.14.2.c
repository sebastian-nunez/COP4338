// Output all combinations of character variables a, b, and c, in the order shown below. If a = 'x', b = 'y', and c = 'z', then the output is:
// xyz xzy yxz yzx zxy zyx
// Your code will be tested in three different programs, with a, b, c assigned with 'x', 'y', 'z', then with '#', '$', '%', then with '1', '2', '3'.

#include <stdio.h>

int main(void) {
    char a;
    char b;
    char c;

    scanf(" %c ", &a);
    scanf(" %c ", &b);
    scanf(" %c ", &c);

    /* Your solution goes here  */
    printf("%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c", a, b, c, a, c, b, b, a, c, b, c, a, c, a, b, c, b, a);

    printf("\n");

    return 0;
}
