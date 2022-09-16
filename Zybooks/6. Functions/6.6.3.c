// Write a function PrintShampooInstructions(), with int parameter numCycles,
// and void return type. If numCycles is less than 1, print "Too few.". If more
// than 4, print "Too many.". Else, print "N: Lather and rinse." numCycles
// times, where N is the cycle number, followed by "Done.". End with a newline.
// Example output with input 2: 1: Lather and rinse. 2: Lather and rinse. Done.

// Hint: Declare and use a loop variable.

#include <stdio.h>

/* Your solution goes here  */
void PrintShampooInstructions(int iNumCycles) {
  if (iNumCycles < 1)
    printf("Too few.\n");
  else if (iNumCycles > 4)
    printf("Too many.\n");
  else {
    for (int i = 1; i <= iNumCycles; i++)
      printf("%d: Lather and rinse.\n", i);
    printf("Done.\n");
  }
}

int main(void) {
  int userCycles;

  scanf("%d", &userCycles);
  PrintShampooInstructions(userCycles);

  return 0;
}
