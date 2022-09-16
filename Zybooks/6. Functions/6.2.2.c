// Define a function PrintFeetInchShort(), with int parameters numFeet and
// numInches, that prints using ' and " shorthand. End with a newline. Remember
// that "\n" in a string literal starts a new line. Ex: PrintFeetInchShort(5, 8)
// prints: 5' 8" Hint: Use \" to print a double quote.

#include <stdio.h>

/* Your solution goes here  */
void PrintFeetInchShort(int iNumFeet, int iNumInches) {
  printf("%d\' %d\"\n", iNumFeet, iNumInches);
}

int main(void) {
  int userFeet;
  int userInches;

  scanf("%d", &userFeet);
  scanf("%d", &userInches);

  PrintFeetInchShort(userFeet,
                     userInches);  // Will be run with (5, 8), then (4, 11)

  return 0;
}
