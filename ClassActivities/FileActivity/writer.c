/**
 * Files Activity
 * usage: writer [-f filename]
 * Sebastian Nunez
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  extern char* optarg;
  extern int optind;
  int c, err = 0;

  int fflag = 0;        // set up the -f flag
  char* filename = "";  // variable to store filename
  static char usage[] = "usage: %s [-f filename]\n";

  //"f" are the allowed flags. : -> previous flag takes an argument
  while ((c = getopt(argc, argv, "f:")) != -1) {
    switch (c) {
      case 'f':
        fflag = 1;
        filename = optarg;
        break;
      case '?':
        err = 1;
        break;
    }
  }

  if ((optind) != argc) {
    // need zero arguments
    printf("optind = %d, argc=%d\n", optind, argc);
    fprintf(stderr, "%s: there are no extra arguments allowed!\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if (err) {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }

  // see what we have
  // printf("fflag = %d\n", fflag);
  // printf("filename = \"%s\"\n", filename);

  // if (optind <
  //    argc) {  // these are the arguments after the command-line options
  //  for (; optind < argc; optind++)
  //    printf("argument: \"%s\"\n", argv[optind]);
  // } else {
  //   printf("no arguments left to process\n");
  // }

  char name[] = "Sebastian";

  if (!fflag) {
    printf("%s\n", name);
    exit(0);
  }

  FILE* outfile = fopen(filename, "w");

  if (outfile == NULL) {
    printf("Unable to create output file '%s'!", filename);
    exit(100);
  }

  fprintf(outfile, "%s\n", name);

  fclose(outfile);
  exit(0);
}
