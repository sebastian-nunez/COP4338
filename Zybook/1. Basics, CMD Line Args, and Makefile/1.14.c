// The location of an input file or output file may not be known before writing
// a program. Instead, a program can use command-line arguments to allow the
// user to specify the location of an input or output file as shown in the
// following program. Assume two text files exist in the same directory as the
// source code named "myfile1.txt" and "myfile2.txt" with the contents shown.
// The sample output shows the results when executing the program for each input
// file and for an input file that does not exist.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* inFile = NULL;  // File pointer
    int fileNum1;         // Data value from file
    int fileNum2;         // Data value from file

    // Check number of arguments
    if (argc != 2) {
        printf("Usage: myprog.exe inputFileName\n");
        return 1;  // 1 indicates error
    }

    // Try to open the file
    printf("Opening file %s.\n", argv[1]);

    inFile = fopen(argv[1], "r");
    if (inFile == NULL) {
        printf("Could not open file %s.\n", argv[1]);
        return -1;  // -1 indicates error
    }

    // Can now use fscanf(inFile, ...) like scanf()
    // myfile.txt should contain two integers, else problems
    printf("Reading two integers.\n");
    fscanf(inFile, "%d %d", &fileNum1, &fileNum2);

    // Done with file, so close it
    printf("Closing file %s.\n\n", argv[1]);
    fclose(inFile);

    // Output values read from file
    printf("num1: %d\n", fileNum1);
    printf("num2: %d\n", fileNum2);
    printf("num1 + num2: %d\n", (fileNum1 + fileNum2));

    return 0;
}
