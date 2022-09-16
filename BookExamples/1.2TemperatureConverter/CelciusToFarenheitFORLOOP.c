#include <stdio.h>

// Constants: Limits of the table
#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celcius Table
    for fahr = 0, 20, ... , 300; floating-point version */
int main() {
  // for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
  //     float celcius = (5.0 / 9.0) * (fahr - 32);

  //     printf("%3d %6.1f\n", fahr, celcius);
  // }

  double nc;
  for (nc = 0; getchar() != EOF; nc++)
    ;
  printf("%.0f,\n", nc);

  // printf("%d", EOF);
  // int c = getchar();
  // while (c != EOF) {
  //     putchar(c);
  //     c = getchar();
  // }

  // Print in reverse order 300 -> 0
  // for (int fahr = 300; fahr >= 0; fahr -= 20) {
  //     float celcius = (5.0 / 9.0) * (fahr - 32);

  //     printf("%3d %6.1f\n", fahr, celcius);
  // }

  return 0;
}
