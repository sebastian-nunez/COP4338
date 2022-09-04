#include <stdio.h>

void PrintPopcornTime(int bagOunces) {
    /* Your solution goes here  */
    if (bagOunces < 3)
        printf("Too small\n");
    else if (bagOunces > 10)
        printf("Too large\n");
    else
        printf("%d seconds\n", 6 * bagOunces);
}

int main(void) {
    int userOunces;

    scanf("%d", &userOunces);
    PrintPopcornTime(userOunces);

    return 0;
}
