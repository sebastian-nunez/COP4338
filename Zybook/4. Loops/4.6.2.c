// Write a do-while loop that continues to prompt a user to enter a number less than 100, until the entered number is actually less than 100. End each prompt with newline. Ex: For the user input 123, 395, 25, the expected output is:
// Enter a number (<100):
// Enter a number (<100):
// Enter a number (<100):
// Your number < 100 is: 25
#include <stdio.h>

int main(void) {
    int userInput;

    /* Your solution goes here  */
    do {
        printf("Enter a number (<100): \n");
        scanf("%d", &userInput);
    } while (userInput >= 100);

    printf("Your number < 100 is: %d\n", userInput);

    return 0;
}
