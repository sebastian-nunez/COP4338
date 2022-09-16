// Assign Barbecue's data member caloriesInSlice with a value read from input.
// Then, assign Ham and Cheese's data member caloriesInSlice with another value
// read from input. Input will contain two integer numbers.

#include <stdio.h>
#include <string.h>

typedef struct Pizza_struct {
  char pizzaName[75];
  int caloriesInSlice;
} Pizza;

int main(void) {
  Pizza pizzasList[2];

  strcpy(pizzasList[0].pizzaName, "Barbecue");
  strcpy(pizzasList[1].pizzaName, "Ham and Cheese");

  /* Your code goes here */
  scanf("%d %d", &pizzasList[0].caloriesInSlice,
        &pizzasList[1].caloriesInSlice);

  printf("A %s slice contains %d calories.\n", pizzasList[0].pizzaName,
         pizzasList[0].caloriesInSlice);
  printf("A %s slice contains %d calories.\n", pizzasList[1].pizzaName,
         pizzasList[1].caloriesInSlice);

  return 0;
}
