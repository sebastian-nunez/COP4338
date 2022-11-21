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
 * This programs reads 1024 alphabetic characters from the std input stream and
 * turns into the capitalized versions.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int STR_BUFFER = 1024;

int main(void) {
  char input[STR_BUFFER];
  fgets(input, STR_BUFFER, stdin);

  for (int i = 0; i < strlen(input); i++) {
    input[i] = toupper(input[i]);
  }

  printf("%s", input);

  return 0;
}
