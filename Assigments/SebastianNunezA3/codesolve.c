/* NAME: Sebastian Nunez
 * STUDENT ID: 6358289
 * CLASS: COP4338 (Assignment 3)
 * DATE: 10/10/22
 *
 * AFFIRMATION OF ORIGINALITY:
 * I affirm that I wrote this program myself
 * without any help from any other people or
 * sources from the internet.
 *
 * PROGRAM DESCRIPTION:
 * This assignment asks you to sort the letters in an input file
 * and print the sorted letters to an output file (or standard output).
 * - Note: input letters will be stored in a doubly linked list
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void solve(char inputFileName[], char outFileName[]);

int main(int argc, char* argv[]) {
  extern char* optarg;
  extern int optind;
  int c, err = 0;

  int oflag = 0;
  char* outFileName = "";
  char* inputFileName = "";
  static char usage[] = "usage: %s [-o output_file_name] input_file_name\n";

  //"o:?" are the allowed flags. : -> previous flag takes an argument
  while ((c = getopt(argc, argv, "o:?")) != -1) {
    switch (c) {
      case 'o':
        oflag = 1;
        outFileName = optarg;
        break;
      case '?':
        err = 1;
        break;
    }
  }
  if ((optind + 1) != argc) {
    // need at least one argument (change +1 to +2 for two, etc. as needeed)
    printf("optind = %d, argc=%d\n", optind, argc);
    fprintf(stderr, "%s: missing input_file_name\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if (err) {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }

  inputFileName = argv[optind++];
  solve(inputFileName, outFileName);
  exit(0);
}

void solve(char inputFileName[], char outFileName[]) {
  bool shouldPrintToFile = (strlen(outFileName) > 0);

  FILE* inFile = fopen(inputFileName, "r");
  if (inFile == NULL) {
    printf("Unable to open file named: %s", inputFileName);
    exit(100);
  }

  FILE* outFile = shouldPrintToFile ? fopen(outFileName, "w") : stdout;
  if (outFile == NULL) {
    printf("Unable to open file named: %s", outFileName);
    exit(100);
  }

  char inputChar;
  while (!feof(inFile)) {
    fscanf(inFile, " %c", &inputChar);

    fprintf(outFile, "%c\n", inputChar);
  }

  fclose(inFile);
  fclose(outFile);
}
