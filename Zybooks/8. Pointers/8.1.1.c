// Write a function call with arguments tensPlace, onesPlace, and userInt. Be
// sure to pass the first two arguments as pointers. Sample output for the given
// program: tensPlace = 4, onesPlace = 1

#include <stdio.h>

void SplitIntoTensOnes(int* tensDigit, int* onesDigit, int DecVal) {
  *tensDigit = (DecVal / 10) % 10;
  *onesDigit = DecVal % 10;
}

int main(void) {
  int tensPlace;
  int onesPlace;
  int userInt;

  scanf("%d", &userInt);

  /* Your solution goes here  */
  SplitIntoTensOnes(&tensPlace, &onesPlace, userInt);

  printf("tensPlace = %d, onesPlace = %d\n", tensPlace, onesPlace);

  return 0;
}
