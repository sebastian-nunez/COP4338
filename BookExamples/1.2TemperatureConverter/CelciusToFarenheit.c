#include <stdio.h>

/* print Fahrenheit-Celcius Table
    for fahr = 0, 20, ... , 300; floating-point version */
int main() {
  float fahr, celcius;
  int lower, upper, step;

  // Limits for the Table
  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%f\n", fahr);
  while (fahr <= upper) {
    celcius = (5.0 / 9.0) * (fahr - 32);
    printf("%3.0f %6.1f\n", fahr, celcius);
    fahr += step;
  }

  return 0;
}
