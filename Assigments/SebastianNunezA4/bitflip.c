/* NAME: Sebastian Nunez
 * STUDENT ID: 6358289
 * CLASS: COP4338 (Assignment 4)
 * DATE: 11/02/22
 *
 * AFFIRMATION OF ORIGINALITY:
 * I affirm that I wrote this program myself
 * without any help from any other people or
 * sources from the internet.
 *
 * PROGRAM DESCRIPTION:
 * This assignment asks you to perform certain bitwise operations obtained
 * using command line arguments. For example, an operation may as you to
 * "flip" all the even bits.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  extern char* optarg;
  extern int optind;
  int c, err = 0;

  int eflag = 0, fflag = 0, aflag = 0, sflag = 0, oflag;
  char* outputFilename = "";
  int32_t intVal;
  static char usage[] = "usage: %s [-e] [-f] [-a] [-s] [-o outputfilename] intval\n";

  //"o:?" are the allowed flags. : -> previous flag takes an argument
  while ((c = getopt(argc, argv, "efaso:?")) != -1) {
    switch (c) {
      case 'e':
        eflag = 1;
        break;
      case 'f':
        fflag = 1;
        break;
      case 'a':
        aflag = 1;
        break;
      case 's':
        sflag = 1;
        break;
      case 'o':
        oflag = 1;
        outputFilename = optarg;
        break;
      case '?':
        err = 1;
        break;
    }
  }
  if ((optind + 1) != argc) {
    // need at one argument for the input file
    printf("optind = %d, argc=%d\n", optind, argc);
    fprintf(stderr, "%s: missing intval\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if (err) {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }

  intVal = (int32_t)strtol(argv[optind++], NULL, 10);

  exit(0);
}
