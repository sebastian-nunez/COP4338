// Double any element's value that is less than controlVal. Ex: If controlVal =
// 10, then dataPoints = {2, 12, 9, 20} becomes {4, 12, 18, 20}.

#include <stdio.h>

int main(void) {
  const int NUM_POINTS = 4;
  int dataPoints[NUM_POINTS];
  int controlVal;
  int i;

  scanf("%d", &controlVal);

  for (i = 0; i < NUM_POINTS; ++i) {
    scanf("%d ", &(dataPoints[i]));
  }

  /* Your solution goes here  */
  for (int i = 0; i < NUM_POINTS; i++) {
    if (dataPoints[i] < controlVal) {
      dataPoints[i] *= 2;
    }
  }

  for (i = 0; i < NUM_POINTS; ++i) {
    printf("%d ", dataPoints[i]);
  }
  printf("\n");

  return 0;
}
