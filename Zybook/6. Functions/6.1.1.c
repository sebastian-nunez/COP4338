// Complete the function definition to return the hours given minutes. Output for sample program:
// 3.500000

#include <stdio.h>

double GetMinutesAsHours(double origMinutes) {
    /* Your solution goes here  */
    return origMinutes / 60.0;
}

int main(void) {
    double minutes;

    scanf("%lf", &minutes);

    // Will be run with 210.0, 3600.0, and 0.0.
    printf("%f\n", GetMinutesAsHours(minutes));

    return 0;
}
