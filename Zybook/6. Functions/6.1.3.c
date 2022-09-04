// Define a function PyramidVolume with double data type parameters baseLength, baseWidth, and pyramidHeight, that returns as a double the volume of a pyramid with a rectangular base. Relevant geometry equations:
// Volume = base area x height x 1/3
// Base area = base length x base width.
// (Watch out for integer division).

#include <stdio.h>

/* Your solution goes here  */
double PyramidVolume(double baseLength, double baseWidth, double pyramidHeight) {
    double baseArea = baseLength * baseWidth;
    return baseArea * pyramidHeight * 1.0 / 3.0;
}

int main(void) {
    double userLength;
    double userWidth;
    double userHeight;

    scanf("%lf", &userLength);
    scanf("%lf", &userWidth);
    scanf("%lf", &userHeight);

    printf("Volume: %f\n", PyramidVolume(userLength, userWidth, userHeight));

    return 0;
}
