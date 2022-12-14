// Complete the code provided to add the appropriate amount to totalDeposit.

#include <stdio.h>

int main(void) {
  enum AcceptedCoins { ADD_QUARTER, ADD_DIME, ADD_NICKEL, ADD_UNKNOWN };
  int totalDeposit = 0;
  int userInput;

  printf("Add coin: 0 (add 25), 1 (add 10), 2 (add 5).  ");
  scanf("%d", &userInput);

  if (userInput == ADD_QUARTER) {
    totalDeposit = totalDeposit + 25;
  }

  /* Your solution goes here  */
  if (userInput == ADD_DIME)
    totalDeposit = totalDeposit + 10;
  else if (userInput == ADD_NICKEL)
    totalDeposit = totalDeposit + 5;
  else
    printf("Invalid coin selection.\n");

  printf("totalDeposit: %d\n", totalDeposit);

  return 0;
}
