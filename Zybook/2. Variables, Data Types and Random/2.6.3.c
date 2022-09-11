// The program is incrementally extended again to calculate the approximate
// number of times the user's heart has beat in his/her lifetime using an
// average heart rate of 72 beats per minutes.

#include <stdio.h>

int main(void) {
    int userAgeYears;
    int userAgeDays;
    int userAgeMinutes;
    int totalHeartbeats;
    int avgBeatsPerMinute = 72;

    printf("Enter your age in years: ");
    scanf("%d", &userAgeYears);

    userAgeDays = userAgeYears * 365;               // Calculate days without leap years
    userAgeDays = userAgeDays + (userAgeYears / 4); // Add days for leap years

    printf("You are %d days old.\n", userAgeDays);

    userAgeMinutes = userAgeDays * 24 * 60; // 24 hours/day, 60 minutes/hour
    printf("You are %d minutes old.\n", userAgeMinutes);

    totalHeartbeats = userAgeMinutes * avgBeatsPerMinute;
    printf("Your heart has beat %d times.\n", totalHeartbeats);

    return 0;
}
