// Command-line arguments are values entered by a user when running a program
// from a command line. A command line exists in some program execution
// environments, wherein a user types a program's name and any arguments at a
// command prompt. To access those arguments, main() can be defined with two
// special parameters argc and argv, as shown below. The program prints provided
// command-line arguments. (The "for" loop is not critical to understanding the
// point, in case you haven't studied for loops yet). The program's executable
// is named argtest.

#include "stdio.h"

int main(int argc, char* argv[]) {
    int i;

    // Prints argc and argv values
    printf("argc: %d\n", argc);
    for (i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
