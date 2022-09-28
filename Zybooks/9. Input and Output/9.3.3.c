// Complete scanf() to read two comma-separated integers from stdin. Assign userInt1 and userInt2 with the user input.
// Ex: "Enter two integers separated by a comma: 3, 5", program outputs: 3 + 5 = 8

#include <stdio.h>

int main(void) {
  int userInt1;
  int userInt2;

  printf("Enter two integers separated by a comma: ");
  scanf(/* Your solution goes here  */ "%d, %d", &userInt1, &userInt2);
  printf("%d + %d = %d\n", userInt1, userInt2, userInt1 + userInt2);

  return 0;
}
