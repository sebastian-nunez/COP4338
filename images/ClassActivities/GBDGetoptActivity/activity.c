/**
 * GBD and Getopt Class Activity
 * usage: activity [-r] -b bval value
 * Sebastian Nunez
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  extern char* optarg;
  extern int optind;
  int c, err = 0;

  // sets up the flags
  int rflag = 0, bflag = 0;

  // variables to hold flag values
  char* bvalArg;

  // usage statement
  static char usage[] = "usage: %s [-r] -b bval value\n";

  //"rb:" are the allowed flags. : -> previous flag takes an argument
  while ((c = getopt(argc, argv, "rb:")) != -1) {
    switch (c) {
      case 'r':
        rflag = 1;
        break;
      case 'b':  // mandatory
        bflag = 1;
        bvalArg = optarg;
        break;
      case '?':
        err = 1;
        break;
    }
  }

  // if any mandatory flags are still 0 (not used) -> exit
  if (bflag == 0) {  // -b was mandatory
    fprintf(stderr, "%s: missing -b option\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if ((optind + 1) != argc) {
    // need at most one extra argument for value
    printf("optind = %d, argc=%d\n", optind, argc);
    fprintf(stderr, "%s: there should be only 1 extra argument for value\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if (err) {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }

  // see what we have
  // printf("rflag = %d\n", rflag);
  // printf("bflag = %d\n", bflag);
  // printf("bval = \"%s\"\n", bvalArg);

  // if (optind < argc) {  // these are the arguments after the command-line options
  //   for (; optind < argc; optind++)
  //     printf("argument: \"%s\"\n", argv[optind]);
  // } else {
  //   printf("no arguments left to process\n");
  // }

  // variable conversion
  int bval = strtod(bvalArg, NULL);
  int value = strtod(argv[optind], NULL);
  int total = bval + value;

  // output
  printf("Total = %d\n", total);

  exit(0);
}
