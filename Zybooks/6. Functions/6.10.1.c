// Define a function CoordTransform() that transforms its first two input
// parameters xVal and yVal into two output parameters xValNew and yValNew. The
// function returns void. The transformation is new = (old + 1) * 2. Ex: If xVal
// = 3 and yVal = 4, then xValNew is 8 and yValNew is 10.

#include <stdio.h>

/* Your solution goes here  */
void CoordTransform(int xValOld, int yValOld, int* xValNew, int* yValNew) {
  *xValNew = (xValOld + 1) * 2;
  *yValNew = (yValOld + 1) * 2;
}

int main(void) {
  int xValNew;
  int yValNew;
  int xValUser;
  int yValUser;

  scanf("%d", &xValUser);
  scanf("%d", &yValUser);

  CoordTransform(xValUser, yValUser, &xValNew, &yValNew);
  printf("(%d, %d) becomes (%d, %d)\n", xValUser, yValUser, xValNew, yValNew);

  return 0;
}
