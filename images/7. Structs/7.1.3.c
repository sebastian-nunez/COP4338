// Write a statement to print the data members of InventoryTag. End with
// newline. Ex: if itemID is 314 and quantityRemaining is 500, print: Inventory
// ID: 314, Qty: 500

#include <stdio.h>

typedef struct InventoryTag_struct {
  int itemID;
  int quantityRemaining;
} InventoryTag;

int main(void) {
  InventoryTag redSweater;

  scanf("%d", &redSweater.itemID);
  scanf("%d", &redSweater.quantityRemaining);

  /* Your solution goes here  */
  printf("Inventory ID: %d, Qty: %d\n", redSweater.itemID,
         redSweater.quantityRemaining);

  return 0;
}
