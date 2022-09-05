// Compute the acceleration of gravity for a given distance from the earth's center, distCenter, assigning the result to accelGravity. The expression for the acceleration of gravity is: (G * M) / (d2), where G is the gravitational constant 6.673 x 10-11, M is the mass of the earth 5.98 x 1024 (in kg) and d is the distance in meters from the earth's center (stored in variable distCenter). Note: Assume distance is at least the radius of the earth.

#include <stdio.h>

int main(void) {
    double G = 6.673e-11;
    double M = 5.98e24;
    double accelGravity;
    double distCenter;
    scanf("%lf", &distCenter);

    /* Your solution goes here  */
    accelGravity = (G * M) / pow(distCenter, 2);

    printf("%lf\n", accelGravity);

    return 0;
}
