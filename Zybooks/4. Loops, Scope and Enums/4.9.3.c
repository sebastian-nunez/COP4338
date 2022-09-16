// Creating correct programs can be hard. Following a good programming process
// helps. What many new programmers do, but shouldn't, is write the entire
// program, compile it, and run it—hoping it works. Debugging such a program can
// be difficult because there may be many distinct bugs.

// Experienced programmers develop programs incrementally, meaning they create a
// simple program version, and then grow the program little-by-little into
// successively more-complete versions.

// The following program allows the user to enter a phone number that includes
// letters. Such letters appear on phone keypads along with numbers, enabling
// phone numbers like 1-555-HOLIDAY. The program converts a phone number having
// numbers/letters into one having numbers only.

// The first program version simply prints each string element, to ensure the
// loop iterates properly.
#include <stdio.h>

int main(void) {
  char phoneChar;  // Current char in phone number string

  printf("Enter phone number: ");

  scanf("%c", &phoneChar);  // Reads first char of user input
  printf("Numbers only: ");

  while (phoneChar != '\n') {
    if (((phoneChar >= '0') && (phoneChar <= '9')) || (phoneChar == '-')) {
      printf("%c", phoneChar);  // Print element as is
                                // FIXME: Add remaining else-if branches
    } else if (((phoneChar >= 'a') && (phoneChar <= 'c')) ||
               ((phoneChar >= 'A') && (phoneChar <= 'C'))) {
      printf("2");
    } else {
      printf("?");
    }

    scanf("%c", &phoneChar);  // Read next char of user input
  }

  printf("\n");

  return 0;
}
