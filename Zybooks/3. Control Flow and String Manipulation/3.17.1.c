// Write an expression that will cause the following code to print "Equal" if
// the value of sensorReading is "close enough" to targetValue. Otherwise, print
// "Not equal". Hint: Use epsilon value 0.0001. Ex: If targetValue is 0.3333 and
// sensorReading is (1.0/3.0), output is: Equal

#include <math.h>
#include <stdio.h>

int main(void) {
  double targetValue;
  double sensorReading;

  scanf("%lf", &targetValue);
  scanf("%lf", &sensorReading);

  if (/* Your solution goes here  */ fabs(sensorReading - targetValue) <
      0.0001) {
    printf("Equal\n");
  } else {
    printf("Not equal\n");
  }

  return 0;
}
