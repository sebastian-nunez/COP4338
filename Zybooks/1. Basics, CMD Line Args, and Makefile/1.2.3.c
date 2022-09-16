// Write two scanf statements to get input values into birthMonth and birthYear.
// Then write a statement to output the month, a slash, and the year. End with
// newline.

// The program will be tested with inputs 1 2000 and then with inputs 5 1950.
// Ex: If the input is 1 2000, the output is: 1/2000

// Note: The input values come from user input, so be sure to use scanf
// statements, as in scanf("%d", &birthMonth), to get those input values (and
// don't assign values directly, as in birthMonth = 1).

#include <stdio.h>

int main(void) {
  int birthMonth;
  int birthYear;

  /* Your solution goes here  */
  scanf("%d %d", &birthMonth, &birthYear);
  printf("%d/%d\n", birthMonth, birthYear);

  return 0;
}
