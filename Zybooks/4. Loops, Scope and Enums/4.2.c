// Below is another loop example. The program asks the user to enter a year, and
// then outputs the approximate number of a person's ancestors who were alive
// for each generation leading back to that year, with the loop computing powers
// of 2 along the way.

#include <stdio.h>

int main(void) {
  const int YEARS_PER_GEN = 20;  // Approx. years per generation
  int userYear;                  // User input
  int consYear;                  // Year being considered
  int numAnc;                    // Approx. ancestors in considered year

  consYear = 2020;
  numAnc = 2;

  printf("Enter a past year (neg. for B.C.): ");
  scanf("%d", &userYear);

  while (consYear >= userYear) {
    printf("Ancestors in %d: %d\n", consYear, numAnc);

    numAnc = 2 * numAnc;                  // Each ancestor had two parents
    consYear = consYear - YEARS_PER_GEN;  // Go back 1 generation
  }

  return 0;
}
