// Write two statements that each use malloc to allocate an int location for
// each pointer. Sample output for given program: numPtr1 = 44, numPtr2 = 99

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int* numPtr1 = NULL;
  int* numPtr2 = NULL;

  /* Your solution goes here  */
  numPtr1 = (int*)malloc(sizeof(int));
  numPtr2 = (int*)malloc(sizeof(int));

  scanf("%d", numPtr1);
  scanf("%d", numPtr2);

  printf("numPtr1 = %d, numPtr2 = %d\n", *numPtr1, *numPtr2);

  free(numPtr1);
  free(numPtr2);

  return 0;
}
