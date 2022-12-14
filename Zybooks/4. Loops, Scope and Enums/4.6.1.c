// Complete the do-while loop to output from 0 to the value of countLimit using
// printVal. Assume the user will only input a positive number. For example, if
// countLimit is 5 the output will be 0 1 2 3 4 5

#include <stdio.h>

int main(void) {
  int countLimit;
  int printVal;

  // Get user input
  scanf("%d", &countLimit);

  printVal = 0;
  do {
    printf("%d ", printVal);
    printVal = printVal + 1;
  } while (/* Your solution goes here  */ printVal <= countLimit);
  printf("\n");

  return 0;
}
