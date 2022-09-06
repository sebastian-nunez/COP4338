# Chapter 5: Arrays and Strings

- [**Chapter 5: Arrays and Strings**](#chapter-5-arrays-and-strings)
  - [General Concept](#general-concept)
  - [Array Declaration](#array-declaration)
  - [Array Initialization](#array-initialization)
  - [Array Iteration (+ Out of Bounds)](#array-iteration--out-of-bounds)
  - [Multiple Arrays](#multiple-arrays)
  - [Swapping Values](#swapping-values)
  - [2D Arrays](#2d-arrays)
  - [Character Arrays](#character-arrays)
  - [String Library \<string.h\>](#string-library-stringh)
  - [I/O: scanf vs fgets \<stdio.h\>](#io-scanf-vs-fgets-stdioh)
  - [Type Checking and Conversion \<ctype.h\>](#type-checking-and-conversion-ctypeh)
  - [Arrays and Strings (Example)](#arrays-and-strings-example)
  - [Annual Salary (Example)](#annual-salary-example)

## General Concept

![General](./5.1.%20Arrays%20General.png)

## Array Declaration

![Array Declaration](./5.2%20Array%20Declaration.png)

## Array Initialization

![Array Initialization](./5.3%20Array%20Initialization.png)

## Array Iteration (+ Out of Bounds)

![Array Iteration](./5.4%20Array%20Iteration.png)
![Array Out of Bounds](./5.4%20Out%20of%20Bounds.png)

## Multiple Arrays

![Multiple Arrays](./5.5%20Multiple%20Arrays.png)

## Swapping Values

![Swapping Values](./5.6%20Swapping%20Values.png)

## 2D Arrays

![2D Arrays](./5.9%202D%20Arrays.png)

## Character Arrays

![Character Arrays](./5.10%20Character%20Arrays.png)
![Character Arrays Common Errors](<./5.10%20String%20Error%20(strcpy).png>)

## String Library <string.h>

![String Library 1](./5.11%20String%20Library%20%3Cstring.h%3E.png)
![String Library 2](./5.11%20String%20Function%20%3Cstring.h%3E.png)

## I/O: scanf vs fgets <stdio.h>

![I/O: scanf vs fgets](<./5.11%20User%20Input%20(scanf%20and%20fgets).png>)

## Type Checking and Conversion <ctype.h>

![Type Checking](./5.12%20Character%20Checking%20%3Cctype.h%3E.png)
![Type Conversion](./5.12%20Character%20Conversion%20%3Cctype.h%3E.png)

## Arrays and Strings (Example)

![Arrays and Strings (Example)](./5.13%20Arrays%20and%20Strings.png)

## Annual Salary (Example)

![Annual Salary (Example)](./5.14%20Example.png)

```c
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
        }  // End inner while loop (search for appropriate table row)

        taxToPay = (int)(annualSalary * taxRate);  // Truncate tax to an integer amount
        annualSalaries[numSalaries] = annualSalary;
        taxesToPay[numSalaries] = taxToPay;

        printf("Annual salary: %d", annualSalaries[numSalaries]);
        printf("\tTax rate: %lf", taxRate);
        printf("\tTax to pay: %d\n", taxesToPay[numSalaries]);
        ++numSalaries;

        // Get the next annual salary
        printf("\nEnter annual salary (0 to exit): \n");
        scanf("%d", &annualSalary);
    }  // End outer while loop (valid annualSalary entered)

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

```
