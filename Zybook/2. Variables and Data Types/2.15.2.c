// Write a program that reads a person's first and last names separated by a space, assuming the first and last names are both single words. Then the program outputs last name, first name. End with newline.

// Example output if the input is: Maya Jones
// Jones, Maya

#include <stdio.h>

int main(void) {
    char firstName[20];
    char lastName[20];

    /* Your solution goes here  */
    scanf("%s %s", firstName, lastName);
    printf("%s, %s\n", lastName, firstName);

    return 0;
}
