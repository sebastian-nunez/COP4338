// Use the function GetUserInfo() to get a user's information. If user enters 20
// and Holly, sample program output is: Holly is 20 years old.

#include <stdio.h>
#include <string.h>

void GetUserInfo(int* userAge, char userName[]) {
    printf("Enter your age: \n");
    scanf("%d", userAge);
    printf("Enter your name: \n");
    scanf("%s", userName);
}

int main(void) {
    int userAge;
    char userName[30];

    /* Your solution goes here  */
    GetUserInfo(&userAge, userName);

    printf("%s is %d years old.\n", userName, userAge);

    return 0;
}
