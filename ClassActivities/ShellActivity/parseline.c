#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100];
    char* token;

    printf("Type a string to read :: ");
    fgets(input, 100, stdin);

    token = strtok(input, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
