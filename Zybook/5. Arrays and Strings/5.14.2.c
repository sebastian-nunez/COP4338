#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const int BASE_TABLE_ELEMENTS = 5;
    const int MAX_ELEMENTS = 10;
    int annualSalary;
    double taxRate;
    int taxToPay;
    int totalSalaries;
    int totalTaxes;
    int numSalaries;
    bool keepLooking;
    int i;

    int salaryBase[] = {20000, 50000, 100000, 999999999};
    double taxBase[] = {.10, .20, .30, .40};
    int annualSalaries[MAX_ELEMENTS];
    int taxesToPay[MAX_ELEMENTS];

    numSalaries = 0;

    printf("\nEnter annual salary (0 to exit): \n");
    scanf("%d", &annualSalary);

    while ((annualSalary > 0) && (numSalaries < MAX_ELEMENTS)) {
        i = 0;
        taxRate = 0;
        keepLooking = true;

        // Search for appropriate table row for given annualSalary
        while ((i < BASE_TABLE_ELEMENTS) && keepLooking) {
            if (annualSalary <= salaryBase[i]) {
                taxRate = taxBase[i];
                keepLooking = false;
            } else {
                ++i;
            }
        } // End inner while loop (search for appropriate table row)

        taxToPay =
            (int)(annualSalary * taxRate); // Truncate tax to an integer amount
        annualSalaries[numSalaries] = annualSalary;
        taxesToPay[numSalaries] = taxToPay;

        printf("Annual salary: %d", annualSalaries[numSalaries]);
        printf("\tTax rate: %lf", taxRate);
        printf("\tTax to pay: %d\n", taxesToPay[numSalaries]);
        ++numSalaries;

        // Get the next annual salary
        printf("\nEnter annual salary (0 to exit): \n");
        scanf("%d", &annualSalary);
    } // End outer while loop (valid annualSalary entered)

    // Sum the annual salaries and taxes to pay and print the totals
    totalSalaries = 0;
    totalTaxes = 0;

    for (i = 0; i < numSalaries; ++i) {
        totalSalaries += annualSalaries[i];
        totalTaxes += taxesToPay[i];
    }
    printf("\nTotal salaries: %d", totalSalaries);
    printf("\tTotal taxes: %d\n", totalTaxes);

    return 0;
}
