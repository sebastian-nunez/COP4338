// Analyzing data is a common programming task. A common data analysis task is
// to find the maximum value in a list of values. A loop can achieve that task
// by updating a max-seen-so-far variable on each iteration.

#include <stdio.h>

/* Outputs max of list of integers
   First value indicates list size
   Ex: 4 -1 9 0 3  yields 9
*/

int main(void) {
  int maxSoFar;
  int currValue;
  int numValues;
  int i;

  scanf("%d", &numValues);

  for (i = 0; i < numValues; ++i) {
    scanf("%d", &currValue);

    if (i == 0) {  // First iteration
      maxSoFar = currValue;
    } else if (currValue > maxSoFar) {
      maxSoFar = currValue;
    }
  }

  if (numValues > 0) {
    printf("Max: %d\n", maxSoFar);
  }

  return 0;
}
