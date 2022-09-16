// Write a for loop to populate array userGuesses with NUM_GUESSES integers.
// Read integers using scanf. Ex: If NUM_GUESSES is 3 and user enters 9 5 2,
// then userGuesses is {9, 5, 2}.

#include <stdio.h>

int main(void) {
  const int NUM_GUESSES = 3;
  int userGuesses[NUM_GUESSES];
  int i;

  /* Your solution goes here  */
  for (int i = 0; i < NUM_GUESSES; i++)
    scanf("%d", &userGuesses[i]);

  for (i = 0; i < NUM_GUESSES; ++i) {
    printf("%d ", userGuesses[i]);
  }

  return 0;
}
