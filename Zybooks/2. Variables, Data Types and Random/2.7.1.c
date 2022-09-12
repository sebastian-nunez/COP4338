// Given sphereRadius, compute the volume of a sphere and assign sphereVolume
// with the result. Use (4.0 / 3.0) to perform floating-point division, instead
// of (4 / 3) which performs integer division.

// Volume of sphere = (4.0 / 3.0) π r3 (Hint: r3 can be computed using *)

#include <math.h>
#include <stdio.h>

int main(void) {
    double sphereVolume;
    double sphereRadius;

    scanf("%lf", &sphereRadius);

    /* Your solution goes here  */
    sphereVolume = (4.0 / 3.0) * M_PI * pow(sphereRadius, 3);

    printf("%.2lf\n", sphereVolume);

    return 0;
}
