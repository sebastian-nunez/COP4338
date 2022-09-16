// Assign isTeenager with true if kidAge is 13 to 19 inclusive. Otherwise,
// assign isTeenager with false.

#include <stdbool.h>
#include <stdio.h>

int main(void) {
  bool isTeenager;
  int kidAge;

  scanf("%d", &kidAge);

  /* Your solution goes here  */
  isTeenager = kidAge >= 13 && kidAge <= 19;

  if (isTeenager) {
    printf("Teen\n");
  } else {
    printf("Not teen\n");
  }

  return 0;
}
