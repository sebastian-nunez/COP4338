/* NAME: Sebastian Nunez
 * STUDENT ID: 6358289
 * CLASS: COP4338 (Assignment 5)
 * DATE: 11/21/22
 *
 * AFFIRMATION OF ORIGINALITY:
 * I affirm that I wrote this program myself
 * without any help from any other people or
 * sources from the internet.
 *
 * PROGRAM DESCRIPTION:
 * This program takes the user's firstname (from cmdline args) and prints it to the std output stream
 */

#include <stdio.h>

int main(int argc, char** argv) {
  printf("%s\n", argv[1]);

  return 0;
}
