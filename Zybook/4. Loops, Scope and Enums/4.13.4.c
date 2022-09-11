// zyDE 4.13.3: Create an annual income and tax table.
// A tax table shows three columns: an annual salary, the tax rate, and the tax
// amount to pay. The program below shows most of the code needed to calculate a
// tax table.

// Run the program below and note the results.
// Alter the program to use a for loop to print a tax table of annual income,
// tax rate, and tax to pay. Use starting and ending annual salaries of 40000
// and 60000, respectively, and a salary increment of 5000. Run the program
// again and note the results. You should have five rows in the tax table. Alter
// the program to add user prompts and read the starting and ending annual
// incomes from user input. Run the program again using 40000 and 60000,
// respectively, and the same salary increment of 5000. You should have the same
// results as before. Alter the program to ask the user for the increment to use
// in addition to the starting and ending annual salaries. Run the program again
// using an increment of 2500. Are the entries for 40000, 45000, 50000, 55000
// and 60000 the same as before?

#include <stdio.h>

int main(void) {
    int annualSalary;
    double taxRate;
    int taxToPay;
    int startingAnnualSalary;
    int endingAnnualSalary;
    int incomeIncrement;

    printf("Enter first annual salary for the table: \n");
    scanf("%d", &startingAnnualSalary);
    printf("Enter last annual salary for the table: \n");
    scanf("%d", &endingAnnualSalary);
    printf("Enter the increment for the table: \n");
    scanf("%d", &incomeIncrement);

    for (annualSalary = startingAnnualSalary; annualSalary <= endingAnnualSalary; annualSalary += incomeIncrement) {
        // Determine the tax rate from the annual salary
        if (annualSalary <= 0) {
            taxRate = 0.0;
        } else if (annualSalary <= 20000) {
            taxRate = 0.10;  // 0.10 is 10% written as a decimal
        } else if (annualSalary <= 50000) {
            taxRate = 0.20;
        } else if (annualSalary <= 100000) {
            taxRate = 0.30;
        } else {
            taxRate = 0.40;
        }

        taxToPay = (int)(annualSalary * taxRate);  // Truncate tax to an integer amount
        printf("Annual salary: %d", annualSalary);
        printf("\tTax rate: %lf", taxRate);
        printf("\tTax to pay: %d\n", taxToPay);
    }

    return 0;
}
