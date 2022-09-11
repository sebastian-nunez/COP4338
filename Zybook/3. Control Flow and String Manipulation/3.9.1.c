#include <stdio.h>

int main(void) {
    int timeHour;     // Time of travel hour (24 hour format)
    int timeMinute;   // Time of travel minute
    char inputColon;  // Used to read time format
    double tollAmount;

    printf("Enter time of travel (HH:MM in 24 hour format): ");

    // Read an integer (hour), colon (char), and integer (minute)
    scanf("%d%c%d", &timeHour, &inputColon, &timeMinute);

    // Determine toll based on hour of travel
    if (timeHour < 6) {  // Before 6:00 am
        tollAmount = 1.55;
    } else if (timeHour < 10) {  // 6 am to 9:59 am
        tollAmount = 4.65;
    } else if (timeHour < 18) {  // 10 am to 5:59 pm
        tollAmount = 2.35;
    } else {  // 6 pm and after
        tollAmount = 1.55;
    }

    // Output time and toll amount
    printf("Toll at %d:", timeHour);

    // Output minute with formatting (discussed elsewhere) to
    // print two digits for minutes.
    printf("%02d is %lf", timeMinute, tollAmount);

    return 0;
}
