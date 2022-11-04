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

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

uint16_t flipBits(uint16_t val, bool even, bool odd);
uint16_t switchBits(uint16_t val);

void print_binary(FILE* outfile, uint16_t n);

int main(int argc, char* argv[]) {
  extern char* optarg;
  extern int optind;
  int c, err = 0;

  // flags
  int eflag = 0, fflag = 0, aflag = 0, sflag = 0, oflag = 0;
  char* outputFilename = "";
  char* intVal = "";
  static char usage[] = "usage: %s [-e] [-f] [-a] [-s] [-o outputfilename] intval\n";

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
  // get the intVal from command line
  intVal = argv[optind++];

  // set up output stream
  FILE* outFile = oflag ? fopen(outputFilename, "w") : stdout;
  if (outFile == NULL) {
    printf("Unable to open file named: \"%s\"\n", outputFilename);
    exit(100);
  }

  uint16_t val = (uint16_t)strtol(intVal, NULL, 10);  // convert intVal (string) to a uint16_t
  uint16_t result = val;

  fprintf(outFile, "Value: %d\n", val);
  // print_binary(outFile, val);

  if (eflag) {
    result = flipBits(val, true, false);  // flip even bits
    // print_binary(outFile, result);
    fprintf(outFile, "Even bits flipped: %d\n", result);
  }

  if (fflag) {
    result = flipBits(val, false, true);  // flip odd bits
    // print_binary(outFile, result);
    fprintf(outFile, "Odd bits flipped: %d\n", result);
  }

  if (aflag) {
    result = flipBits(val, true, true);  // flip even and odd bits
    // print_binary(outFile, result);
    fprintf(outFile, "All bits flipped: %d\n", result);
  }

  if (sflag) {
    result = switchBits(val);
    // print_binary(outFile, result);
    fprintf(outFile, "Switched all bits: %d\n", result);
  }

  exit(0);
}

/**
 * Print the binary representation of 'val' to output stream 'outfile'.
 * Approach:
 * 1. create a mask to select a bit (starting with the leftmost bit)
 * 2. Apply the mask to the val (extract the actual bit at the mask position)
 * 3. Print "1" or "0" depending on the value at the mask location
 *
 */
void print_binary(FILE* outFile, uint16_t val) {
  for (int shift = 15; shift >= 0; shift--) {
    // mask used to select the bit a "shift" location
    uint16_t mask = 0b1 << shift;

    if (val & mask)
      fprintf(outFile, "1");
    else
      fprintf(outFile, "0");
  }

  fprintf(outFile, "\n");
}

/**
 * Flips the even, odd, or all bits of a given 'val' and returns the 'result'.
 * Depending on the arguments, the function will perform different operations.
 *
 * Examples:
 * flipBits(NUMBER, true, false)  -> flips only EVEN bits
 * flipBits(NUMBER, false, true)  -> flips only ODD bits
 * flipBits(NUMBER, true, true)   -> flips only ALL bits
 * flipBits(NUMBER, false, false) -> returns the original number
 *
 * In general the approach is as follows:
 * 1. create a mask to isolate a single bit
 * 2. use the mask to obtain the actual bit in 'val'
 * 3. perform flip operation on the selected bit (even or odd)
 * 4. copy the 'flipped' bit to in the 'result'
 *

 */
uint16_t flipBits(uint16_t val, bool even, bool odd) {
  // flipping none of the bits -> return the same value
  if (!even && !odd) {
    return val;
  }

  // flipping all the bits -> return the bitwise complement
  if (even && odd) {
    return ~val;
  }

  uint16_t result = 0b0;  // result is 0000...0000 (32 bit)

  for (int shift = 0; shift <= 15; shift++) {
    // mask used to select the bit a "shift" location
    uint16_t mask = 0b1 << shift;

    // get the actual value at the location selected in 'val'
    uint16_t bit = val & mask;

    // flip the bits as needed
    if ((even && shift % 2 == 0) || (odd && shift % 2 != 0)) {
      bit = ~bit & mask;  // find the complement of the bit
    }

    result = result | bit;  // copy the "masked" bit to the result
  }

  return result;
}

/**
 * Takes the bits and switches them around from right to left
 * and returns the result (i.e. rightmost bit becomes the leftmost bit)
 *
 * Approach:
 * 1. create a mask to isolate a single bit (starting at the rightmost bit)
 * 2. use the mask to obtain the actual bit in 'val'
 * 4. copy the selected 'bit' to the result (starting with the leftmost bit)
 */
uint16_t switchBits(uint16_t val) {
  uint16_t result = 0b0;

  for (int shift = 0, endLoc = 15; shift <= 15 && endLoc >= 0; shift++, endLoc--) {
    // select bit at "shift" location
    uint16_t mask = 0b1 << shift;

    // get the actual value at the location selected in 'val'
    uint16_t bit = val & mask;

    bit = bit >> shift;  // place the selected bit at location 0

    bit = bit << endLoc;    // place the bit at the 'end location'
    result = result | bit;  // copy the bit to the result
  }

  return result;
}
