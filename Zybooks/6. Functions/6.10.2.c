// Write a function call to ConvertTime() to store the number of millennia,
// decades, and years within the integer variables numMillennia, numDecades, and
// numYears, respectively.

// Ex: If the input is 2013, then the output is:

// Millennia: 2
// Decades: 1
// Years: 3

#include <stdio.h>

void ConvertTime(int totalYears, int* numMillennia, int* numDecades,
                 int* numYears) {
  *numMillennia = totalYears / 1000;
  totalYears = totalYears % 1000;

  *numDecades = totalYears / 10;
  totalYears = totalYears % 10;

  *numYears = totalYears;
}

int main(void) {
  int totalYears;
  int numMillennia;
  int numDecades;
  int numYears;

  scanf("%d", &totalYears);

  /* Your code goes here */
  ConvertTime(totalYears, &numMillennia, &numDecades, &numYears);

  printf("Millennia: %d\n", numMillennia);
  printf("Decades: %d\n", numDecades);
  printf("Years: %d\n", numYears);

  return 0;
}
