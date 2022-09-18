// Complete the function ConvertToDecadesAndYears to convert totalYears to
// decades and years. Return decades and years using the TimeDecadesYears
// struct. Ex: 26 years is 2 decades and 6 years.

#include <stdio.h>

typedef struct TimeDecadesYears_struct {
  int decadesVal;
  int yearsVal;
} TimeDecadesYears;

TimeDecadesYears ConvertToDecadesAndYears(int totalYears) {
  TimeDecadesYears tempVal;

  /* Your code goes here */
  tempVal.decadesVal = totalYears / 10;
  tempVal.yearsVal = totalYears % 10;

  return tempVal;
}

int main(void) {
  TimeDecadesYears elapsedYears;
  int totalYears;

  scanf("%d", &totalYears);

  elapsedYears = ConvertToDecadesAndYears(totalYears);

  printf("%d decades and %d years\n", elapsedYears.decadesVal,
         elapsedYears.yearsVal);

  return 0;
}
