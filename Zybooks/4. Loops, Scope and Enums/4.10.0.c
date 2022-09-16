// The nested for loops generate all possible meal options for the number of
// empanadas and tacos that can be purchased. The inner loop body calculates the
// cost of the current meal option. If equal to the user's money, the search is
// over, so the break statement immediately exits the inner loop. The outer loop
// body also checks if equal, and if so that break statement exits the outer
// loop.

// The program could be written without break statements, but the loop's
// condition expressions would be more complex and the program would require
// additional code, perhaps being harder to understand.

#include <stdio.h>

int main(void) {
  const int EMPANADA_COST = 3;
  const int TACO_COST = 4;

  int userMoney;
  int numTacos;
  int numEmpanadas;
  int mealCost;
  int maxEmpanadas;
  int maxTacos;

  mealCost = 0;

  printf("Enter money for meal: ");
  scanf("%d", &userMoney);

  maxEmpanadas = userMoney / EMPANADA_COST;
  maxTacos = userMoney / TACO_COST;

  for (numTacos = 0; numTacos <= maxTacos; ++numTacos) {
    for (numEmpanadas = 0; numEmpanadas <= maxEmpanadas; ++numEmpanadas) {
      mealCost = (numEmpanadas * EMPANADA_COST) + (numTacos * TACO_COST);

      // Find first meal option that exactly matches user money
      if (mealCost == userMoney) {
        break;
      }
    }

    // If meal option exactly matching user money is found,
    // break from outer loop as well
    if (mealCost == userMoney) {
      break;
    }
  }

  if (mealCost == userMoney) {
    printf("$%d buys %d empanadas and %d tacos without change.\n", mealCost,
           numEmpanadas, numTacos);
  } else {
    printf("You cannot buy a meal without having change left over.\n");
  }

  return 0;
}
