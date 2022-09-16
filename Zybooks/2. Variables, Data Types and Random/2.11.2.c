// A cashier distributes change using the maximum number of five dollar bills,
// followed by one dollar bills. For example, 19 yields 3 fives and 4 ones.
// Write a single statement that assigns the number of one dollar bills to
// variable numOnes, given amountToChange. Hint: Use the % operator.
#include <stdio.h>

int main(void) {
  int amountToChange;
  int numFives;
  int numOnes;

  scanf("%d", &amountToChange);
  numFives = amountToChange / 5;

  /* Your solution goes here  */
  numOnes = amountToChange - (numFives * 5);

  printf("numFives: %d\n", numFives);
  printf("numOnes: %d\n", numOnes);

  return 0;
}
