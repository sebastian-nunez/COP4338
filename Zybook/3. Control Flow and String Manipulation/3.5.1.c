// Write an expression that prints "Eligible" if userAge is between 18 and 25 inclusive.
// Ex: 17 prints "Ineligible", 18 prints "Eligible".

#include <stdio.h>

int main(void) {
    int userAge;

    scanf("%d", &userAge);

    if (/* Your solution goes here  */ userAge >= 18 && userAge <= 25) {
        printf("Eligible\n");
    } else {
        printf("Ineligible\n");
    }

    return 0;
}
