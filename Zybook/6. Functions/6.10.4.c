// Define a function AdjustState() that takes one integer parameter as the air
// temperature and one character parameter passed by pointer as the thermostat's
// state ('L' means low, 'S' means stable, and 'H' means high). The function
// updates the state with:

// 'L' if the temperature is less than 60.
// 'H' if the temperature is greater than 60.
// The function returns true if the state has been updated, and returns false
// otherwise. Ex: If the input is 63, then the output is:

// Thermostat state is changed to H.
#include <stdbool.h>
#include <stdio.h>

/* Your code goes here */
bool AdjustState(int airTemp, char *thermoState) {
    if (airTemp < 60) {
        *thermoState = 'L';
    } else if (airTemp > 60) {
        *thermoState = 'H';
    } else {
        return false;
    }

    return true;
}

int main(void) {
    int airTemperature;
    char thermostatState;
    bool isChanged;

    thermostatState = 'S';
    scanf("%d", &airTemperature);

    isChanged = AdjustState(airTemperature, &thermostatState);

    if (isChanged) {
        printf("Thermostat state is changed to %c.\n", thermostatState);
    } else {
        printf("Thermostat state %c is not changed.\n", thermostatState);
    }

    return 0;
}
