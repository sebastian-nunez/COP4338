#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Number of command line arguments: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    char string[] = "213.32";
    double number = strtod(string, NULL);
    printf("%.13f\n", number);

    printf("Max value of an int: %i\n", INT_MAX);
    printf("Max value of an long: %li\n", LONG_MAX);
    return 1;
}
