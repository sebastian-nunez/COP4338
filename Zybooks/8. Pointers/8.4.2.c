// Write two statements to assign numApples with 10 and numOranges with 3.
// Sample output for given program: Apples: 10 Oranges: 3

#include <stdio.h>
#include <stdlib.h>

typedef struct bagContents_struct {
  int numApples;
  int numOranges;
} bagContents;

void bagContents_PrintBag(bagContents* itemPtr) {
  if (itemPtr == NULL) return;

  printf("Apples: %d\n", itemPtr->numApples);
  printf("Oranges: %d\n", itemPtr->numOranges);
}

int main(void) {
  bagContents* groceryPtr = NULL;

  groceryPtr = (bagContents*)malloc(sizeof(bagContents));

  /* Your solution goes here  */
  groceryPtr->numApples = 10;
  groceryPtr->numOranges = 3;

  bagContents_PrintBag(groceryPtr);

  return 0;
}
