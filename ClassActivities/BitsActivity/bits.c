#include <stdbool.h>
#include <stdio.h>

int main(void) {
  unsigned long long num;
  short shiftDirection;
  int bits;

  printf("Enter an unsigned number :: ");
  scanf(" %lld", &num);

  printf("Enter [0] to shift left and [1] to shift right :: ");
  scanf(" %hd", &shiftDirection);

  printf("Enter the number of bits to shift :: ");
  scanf(" %d", &bits);

  if (shiftDirection == 0) {
    num = num << bits;
  } else {
    num = num >> bits;
  }

  printf("Result: %lld\n", num);
  return 0;
}
