// Declare an array named pizzasInStore that stores 3 items of type Pizza.

#include <stdio.h>
#include <string.h>

typedef struct Pizza_struct {
  char pizzaName[75];
  char ingredients[75];
} Pizza;

int main(void) {
  /* Your code goes here */
  Pizza pizzasInStore[3];

  strcpy(pizzasInStore[0].pizzaName, "Barbecue");
  strcpy(pizzasInStore[1].pizzaName, "Carbonara");
  strcpy(pizzasInStore[2].pizzaName, "Ham and Cheese");
  strcpy(pizzasInStore[0].ingredients, "Beef, chicken, bacon, barbecue sauce");
  strcpy(pizzasInStore[1].ingredients, "Mushrooms, onion, creamy sauce");
  strcpy(pizzasInStore[2].ingredients, "Ham, cheese, bacon");

  printf("%s: %s\n", pizzasInStore[0].pizzaName, pizzasInStore[0].ingredients);
  printf("%s: %s\n", pizzasInStore[1].pizzaName, pizzasInStore[1].ingredients);
  printf("%s: %s\n", pizzasInStore[2].pizzaName, pizzasInStore[2].ingredients);

  return 0;
}
