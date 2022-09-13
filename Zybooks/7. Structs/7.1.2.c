// Define a struct named PatientData that contains two integer data members named heightInches  and weightPounds. Sample
// output for the given program with inputs 63 115: Patient data: 63 in, 115 lbs

#include <stdio.h>

/* Your solution goes here  */
typedef struct PatientData {
    int heightInches;
    int weightPounds;
} PatientData;

int main(void) {
    PatientData lunaLovegood;

    scanf("%d", &lunaLovegood.heightInches);
    scanf("%d", &lunaLovegood.weightPounds);

    printf("Patient data: %d in, %d lbs\n", lunaLovegood.heightInches, lunaLovegood.weightPounds);

    return 0;
}
