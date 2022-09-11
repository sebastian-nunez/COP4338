// zyDE 4.13.2: Calculate adjusted salary and tax with deductions: Using loops.
// A program may execute the same computations repeatedly.

// The program below repeatedly asks the user to enter an annual salary,
// stopping when the user enters 0 or less. For each annual salary, the program
// determines the tax rate and computes the tax to pay.

// Run the program below with annual salaries of 40000, 90000, and then 0.
// Modify the program to use a while loop inside the given while loop. The new
// inner loop should repeatedly ask the user to enter a salary deduction,
// stopping when the user enters a 0 or less. The deductions are summed and then
// subtracted from the annual income, giving an adjusted gross income. The tax
// rate is then calculated from the adjusted gross income. Run the program with
// the following input: 40000, 7000, 2000, 0, and 0. Note that the 7000 and 2000
// are deductions.

#include <stdio.h>

int main(void) {
    const char SALARY_PROMPT[] = "\nEnter annual salary (0 to exit): ";
    const char PROMPT_DEDUCTION[] = "Enter a deduction (0 to end deductions): ";
    int annualSalary;
    int oneDeduction;
    int adjustedSalary;
    int totalDeductions;
    double taxRate;
    int taxToPay;

    printf("%s\n", SALARY_PROMPT);
    scanf("%d", &annualSalary);

    while (annualSalary > 0) {
        totalDeductions = 0; // Start with 0 for each annual salary
        printf("%s\n", PROMPT_DEDUCTION);
        scanf("%d", &oneDeduction);

        while (oneDeduction > 0) {
            totalDeductions += oneDeduction;
            printf("%s\n", PROMPT_DEDUCTION);
            scanf("%d", &oneDeduction);
        }

        // Determine the tax rate from the adjusted salary
        adjustedSalary = annualSalary - totalDeductions;
        if (adjustedSalary <= 0) {
            adjustedSalary = 0;
            taxRate = 0.0;
        } else if (adjustedSalary <= 20000) {
            taxRate = 0.10; // 0.10 is 10% written as a decimal
        } else if (adjustedSalary <= 50000) {
            taxRate = 0.20;
        } else if (adjustedSalary <= 100000) {
            taxRate = 0.30;
        } else {
            taxRate = 0.40;
        }

        taxToPay = (int)(adjustedSalary * taxRate); // Truncate tax to an integer amount
        printf("Annual salary: %d\n", annualSalary);
        printf("\nDeductions: %d\n", totalDeductions);
        printf("Adjusted salary after deductions: %d\n", adjustedSalary);
        printf("Tax rate: %lf\n", taxRate);
        printf("Tax to pay: %d\n", taxToPay);

        // Get the next annual salary
        printf("%s\n", SALARY_PROMPT);
        scanf("%d", &annualSalary);
    }

    return 0;
}
