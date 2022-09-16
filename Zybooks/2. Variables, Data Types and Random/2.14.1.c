// Print a message telling a user to press the letterToQuit key numPresses times
// to quit. End with newline. Ex: If letterToQuit = 'q' and numPresses = 2,
// print: Press the q key 2 times to quit.

#include <stdio.h>

int main(void) {
  char letterToQuit;
  int numPresses;

  scanf(" %c ", &letterToQuit);
  scanf("%d", &numPresses);

  /* Your solution goes here  */
  printf("Press the %c key %d times to quit.\n", letterToQuit, numPresses);

  return 0;
}
