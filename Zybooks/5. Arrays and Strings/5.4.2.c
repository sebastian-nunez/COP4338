// Assign numMatches with the number of elements in userValues that equal
// matchValue. userValues has NUM_VALS elements. Ex: If userValues is {2, 1, 2,
// 2} and matchValue is 2 , then numMatches should be 3.

// Your code will be tested with the following values:
// matchValue: 2, userValues: {2, 1, 2, 2} (as in the example program above)
// matchValue: 0, userValues: {0, 0, 0, 0}
// matchValue: 10, userValues: {20, 50, 70, 100}
// (Notes)

#include <stdio.h>

int main(void) {
  const int NUM_VALS = 4;
  int userValues[NUM_VALS];
  int i;
  int matchValue;
  int numMatches = -99;  // Assign numMatches with 0 before your for loop

  scanf("%d", &matchValue);

  for (i = 0; i < NUM_VALS; ++i) {
    scanf("%d", &(userValues[i]));
  }

  /* Your solution goes here  */
  numMatches = 0;
  for (int i = 0; i < 4; i++)
    if (userValues[i] == matchValue) numMatches++;

  printf("matchValue: %d, numMatches: %d\n", matchValue, numMatches);

  return 0;
}
