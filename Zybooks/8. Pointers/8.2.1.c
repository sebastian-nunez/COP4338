// If the input is negative, make numItemsPointer be null. Otherwise, make
// numItemsPointer point to numItems and multiply the value to which
// numItemsPointer points by 10. Ex: If the user enters 99, the output should
// be: Items: 990

#include <stdio.h>

int main(void) {
  int* numItemsPointer;
  int numItems;

  scanf("%d", &numItems);

  /* Your solution goes here  */
  if (numItems < 0)
    numItemsPointer = NULL;
  else {
    numItemsPointer = &numItems;
    *numItemsPointer *= 10;
  }

  if (numItemsPointer == NULL) {
    printf("Items is negative\n");
  } else {
    printf("Items: %d\n", *numItemsPointer);
  }

  return 0;
}
