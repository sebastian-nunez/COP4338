// Write a function so that the main() code below can be replaced by the simpler
// code that calls function MphAndMinutesToMiles(). Original main():

// int main(void) {
//    double milesPerHour;
//    double minutesTraveled;
//    double hoursTraveled;
//    double milesTraveled;

//    scanf("%lf", &milesPerHour);
//    scanf("%lf", &minutesTraveled);

//    hoursTraveled = minutesTraveled / 60.0;
//    milesTraveled = hoursTraveled * milesPerHour;

//    printf("Miles: %lf\n", milesTraveled);

//    return 0;
// }

#include <stdio.h>

/* Your solution goes here  */
double MphAndMinutesToMiles(double dMilesPerHour, double dMinutesTraveled) {
  return dMilesPerHour * (dMinutesTraveled / 60.0);
}

int main(void) {
  double milesPerHour;
  double minutesTraveled;

  scanf("%lf", &milesPerHour);
  scanf("%lf", &minutesTraveled);

  printf("Miles: %lf\n", MphAndMinutesToMiles(milesPerHour, minutesTraveled));

  return 0;
}
