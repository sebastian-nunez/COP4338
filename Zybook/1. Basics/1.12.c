#include <stdio.h>

int main(void) {
    char firstName1[50];
    char lastName1[50];
    char firstName2[50];
    char lastName2[50];

    printf("What is the first person's first name?\n");
    scanf("%s", firstName1);
    printf("What is the first person's last name?\n");
    scanf("%s", lastName1);

    printf("What is the second person's first name?\n");
    scanf("%s", firstName2);
    printf("What is the second person's last name?\n");
    scanf("%s", lastName2);

    printf("Here are some common married-couple names:\n");
    printf("%s %s and %s %s\n", firstName1, lastName1, firstName2, lastName2);
    printf("%s and %s %s\n", firstName1, firstName2, lastName1);
    printf("%s and %s %s\n", firstName1, firstName2, lastName2);
    printf("%s and %s %s-%s\n", firstName1, firstName2, lastName1, lastName2);
    printf("%s and %s %s-%s\n", firstName1, firstName2, lastName2, lastName1);

    return 0;
}
