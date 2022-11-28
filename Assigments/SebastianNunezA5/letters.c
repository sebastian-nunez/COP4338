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
 * This program prints the letters 'a' - 'z' to the std output stream.
 *
 * NOTE: I've decided to print the letters in lowercase so we can see the
 * difference when we run "letters | userinput". As we know, userinput should
 * capitalize all the letters that came in from the std input stream;
 * so, if the letters were already capitalized, we couldn't see a difference.
 */

#include <stdio.h>

int main(void) {
  for (int i = 'A'; i <= 'Z'; i++) {
    printf("%c", i);
  }
  printf("\n");
  return 0;
}
