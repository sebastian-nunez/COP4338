#include <stdio.h>
#include <stdint.h>

int main(void) {
  uint32_t num;
  int shiftDirection;
  int bits;

  printf("Enter an unsigned number :: ");
  scanf(" %d", &num);

  printf("Enter [0] to shift left and [1] to shift right :: ");
  scanf(" %d", &shiftDirection);

  printf("Enter the number of bits to shift :: ");
  scanf(" %d", &bits);

  if (shiftDirection == 0) {
    num = num << bits;
  } else {
    num = num >> bits;
  }

  printf("Result: %d\n", num);
  return 0;
}
