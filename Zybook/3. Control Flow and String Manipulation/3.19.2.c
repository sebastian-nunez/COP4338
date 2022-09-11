// Income tax is calculated based on annual income. The tax rate is determined
// with a tiered approach: Income above a particular tier level is taxed at that
// level's rate.

// Run the program with an annual income of 120000. Note the tax rate and tax to
// pay. Modify the program to add a new tier: Annual income above 50000 but less
// than or equal to 100000 is taxed at the rate of 30%, and annual income above
// 100000 is taxed at 40%. Run the program again with an annual income of
// 120000. What is the tax rate and tax to pay now? Run the program again with
// an annual income of 60000. (Change the input area below the program.)
// Challenge: What happens if a negative annual salary is entered? Modify the
// program to print an error message in that case.

#include <stdio.h>

int main(void) {
    int annualSalary;
    double taxRate;
    int taxToPay;

    printf("Enter annual salary: \n");
    scanf("%d", &annualSalary);

    // Determine the tax rate from the annual salary
    // FIXME: Write code to address the challenge question above
    if (annualSalary <= 20000) {
        taxRate = 0.10;
    } else if (annualSalary <= 50000) {
        taxRate = 0.20;
    }
    // FIXME: Add tier
    else {
        taxRate = 0.30;
    }

    taxToPay =
        (int)(annualSalary * taxRate); // Truncate tax to an integer amount

    printf("Annual Salary: %d\n", annualSalary);
    printf("Tax rate: %lf\n", taxRate);
    printf("Tax to pay: %d\n", taxToPay);

    return 0;
}
