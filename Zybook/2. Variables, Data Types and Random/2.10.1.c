// The example below computes the growth of a biological mass, such as a tree. If the growth rate is 5% per year, the program computes 1.05 raised to the number of years. A similar program could calculate growth of money given an interest rate.

#include <math.h>
#include <stdio.h>

int main(void) {
    double initMass;    // Initial mass of a substance
    double growthRate;  // Annual growth rate
    double yearsGrow;   // Years of growth
    double finalMass;   // Final mass after those years

    printf("Enter initial mass: ");
    scanf("%lf", &initMass);

    printf("Enter growth rate (Ex: 0.05 is 5%/year): ");
    scanf("%lf", &growthRate);

    printf("Enter years of growth: ");
    scanf("%lf", &yearsGrow);

    finalMass = initMass * pow(1.0 + growthRate, yearsGrow);
    // Ex: Rate of 0.05 yields initMass * 1.05^yearsGrow

    printf("Final mass after %lf years is: %lf\n",
           yearsGrow, finalMass);

    return 0;
}
