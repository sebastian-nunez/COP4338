// A drink costs 2 dollars. A taco costs 3 dollars. Given the number of each,
// compute total cost and assign totalCost with the result. Ex: 4 drinks and 6
// tacos yields totalCost of 26.

#include <stdio.h>

int main(void) {
  int numDrinks;
  int numTacos;
  int totalCost;

  scanf("%d", &numDrinks);
  scanf("%d", &numTacos);

  /* Your solution goes here  */
  totalCost = (numDrinks * 2) + (numTacos * 3);

  printf("Total cost: %d\n", totalCost);

  return 0;
}
