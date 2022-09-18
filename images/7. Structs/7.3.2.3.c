// Assign listOfPizzas's first element's caloriesPerSlice with the value in
// listOfPizzas's second element's caloriesPerSlice.

#include <stdio.h>
#include <string.h>

typedef struct Pizza_struct {
  char pizzaName[75];
  int caloriesPerSlice;
} Pizza;

int main(void) {
  Pizza listOfPizzas[2];

  scanf("%s", listOfPizzas[0].pizzaName);
  scanf("%d", &listOfPizzas[0].caloriesPerSlice);

  scanf("%s", listOfPizzas[1].pizzaName);
  scanf("%d", &listOfPizzas[1].caloriesPerSlice);

  /* Your code goes here */
  listOfPizzas[0].caloriesPerSlice = listOfPizzas[1].caloriesPerSlice;

  printf("A %s slice contains %d calories.\n", listOfPizzas[0].pizzaName,
         listOfPizzas[0].caloriesPerSlice);
  printf("A %s slice contains %d calories.\n", listOfPizzas[1].pizzaName,
         listOfPizzas[1].caloriesPerSlice);

  return 0;
}
