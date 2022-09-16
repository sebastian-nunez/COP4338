// Write an expression that executes the loop while the user enters a number
// greater than or equal to 0.

// Note: These activities may test code with different test values. This
// activity will perform three tests, with user input of 9, 5, 2, -1, then with
// user input of 0, -17, then with user input of -1. See "How to Use zyBooks".

// Also note: If the submitted code has an infinite loop, the system will stop
// running the code after a few seconds, and report "Test aborted."

#include <stdio.h>

int main(void) {
  int userNum;

  scanf("%d", &userNum);

  while (/* Your solution goes here  */ userNum >= 0) {
    printf("Body\n");
    scanf("%d", &userNum);
  }
  printf("Done.\n");

  return 0;
}
