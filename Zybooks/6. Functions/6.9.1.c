// Using the CelsiusToKelvin function as a guide, create a new function,
// changing the name to KelvinToCelsius, and modifying the function accordingly.

#include <stdio.h>

double CelsiusToKelvin(double valueCelsius) {
    double valueKelvin;

    valueKelvin = valueCelsius + 273.15;

    return valueKelvin;
}

/* Your solution goes here  */
double KelvinToCelsius(double valueKelvin) {
    double valueCelsius;

    valueCelsius = valueKelvin - 273.15;

    return valueCelsius;
}

int main(void) {
    double valueC;
    double valueK;

    valueC = 10.0;
    printf("%lf C is %lf K\n", valueC, CelsiusToKelvin(valueC));

    scanf("%lf", &valueK);
    printf("%lf is %lf C\n", valueK, KelvinToCelsius(valueK));

    return 0;
}
