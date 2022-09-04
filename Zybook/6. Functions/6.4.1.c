// Define a function CalcPyramidVolume with double data type parameters baseLength, baseWidth, and pyramidHeight, that returns as a double the volume of a pyramid with a rectangular base. CalcPyramidVolume() calls the given CalcBaseArea() function in the calculation.

// Relevant geometry equations:
// Volume = base area x height x 1/3
// Base area = base length x base width.
// (Watch out for integer division).

#include <stdio.h>

double CalcBaseArea(double baseLength, double baseWidth) {
    return baseLength * baseWidth;
}

/* Your solution goes here  */
double CalcPyramidVolume(double dBaseLength, double dBaseWidth, double dPyramidHeight) {
    return CalcBaseArea(dBaseLength, dBaseWidth) * 1.0 / 3.0 * dPyramidHeight;
}

int main(void) {
    double userLength;
    double userWidth;
    double userHeight;

    scanf("%lf", &userLength);
    scanf("%lf", &userWidth);
    scanf("%lf", &userHeight);

    printf("Volume: %lf\n", CalcPyramidVolume(userLength, userWidth, userHeight));

    return 0;
}
