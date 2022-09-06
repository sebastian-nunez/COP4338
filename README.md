# COP4338 - Systems Programming

## Table of Contents

- [**Chapter 4: Loops, Scope and Enums**](#chapter-4-loops-scope-and-enums)

  - [While Loops](#while-loops)
  - [For Loops](#for-loops)
  - [Pre vs Post Operators](#pre-vs-post-operators)
  - [Do-While Loops](#do-while-loops)
  - [Loops and Strings](#loops-and-strings)
  - [Nested Loops](#nested-loops)
  - [Break Statement](#break-statement)
  - [Continue Statement](#continue-statement)
  - [Loop Indexing](#loop-indexing)
  - [Variable Scope](#variable-scope)
  - [Enums](#enums)
  - [Enums Example](#enums-example)

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

## Chapter 4: Loops, Scope and Enums

### While Loops

![While Loops](./images/4.2%20While%20Loops.png)

### For Loops

![For Loops](./images/4.4%20For%20Loops.png)
![For Loops](./images/4.4%20For%20Loop%20Styling.png)

### Pre vs Post Operators

![Pre vs Post Operators](./images/4.4%20Pre%20vs%20Post%20Increment.png)

### Do-While Loops

![Do-While Loops](./images/4.6%20Do-While%20Loops.png)

### Loops and Strings

![Loops and Strings](./images/4.7%20Loops%20and%20Strings.png)

### Nested Loops

![Nested Loops](./images/4.8%20Nested%20Loops.png)

### Break Statement

![Break Statement](./images/4.10%20Break%20Statement.png)

### Continue Statement

![Continue Statement](./images/4.10%20Continue%20Statement.png)

### Loop Indexing

![Loop Indexing](./images/4.11%20Loop%20Index.png)

### Variable Scope

![Variable Scope](./images/4.11%20Variable%20Scope.png)

### Enums

![Enums](./images/4.12%20Enums.png)

### Enums Example

![Enums Example](./images/4.12%20Enum%20Example.png)

```c
#include <stdio.h>

/* Manual controller for traffic light */
int main(void) {
    enum LightState { LS_RED,
                      LS_GREEN,
                      LS_YELLOW,
                      LS_DONE };
    enum LightState lightVal;
    char userCmd;

    lightVal = LS_RED;
    userCmd = '-';

    printf("User commands: n (next), r (red), q (quit).\n\n");

    lightVal = LS_RED;
    while (lightVal != LS_DONE) {
        if (lightVal == LS_GREEN) {
            printf("Green light  ");
            scanf(" %c", &userCmd);
            if (userCmd == 'n') {  // Next
                lightVal = LS_YELLOW;
            }
        } else if (lightVal == LS_YELLOW) {
            printf("Yellow light  ");
            scanf(" %c", &userCmd);
            if (userCmd == 'n') {  // Next
                lightVal = LS_RED;
            }
        } else if (lightVal == LS_RED) {
            printf("Red light  ");
            scanf(" %c", &userCmd);
            if (userCmd == 'n') {  // Next
                lightVal = LS_GREEN;
            }
        }

        if (userCmd == 'r') {  // Force immediate red
            lightVal = LS_RED;
        } else if (userCmd == 'q') {  // Quit
            lightVal = LS_DONE;
        }
    }

    printf("Quit program.\n");

    return 0;
}

```

[Back to top](#table-of-contents)

## Chapter 5: Arrays and Strings

### General Concept

![General](./images/5.1.%20Arrays%20General.png)

### Array Declaration

![Array Declaration](./images/5.2%20Array%20Declaration.png)

### Array Initialization

![Array Initialization](./images/5.3%20Array%20Initialization.png)

### Array Iteration (+ Out of Bounds)

![Array Iteration](./images/5.4%20Array%20Iteration.png)
![Array Out of Bounds](./images/5.4%20Out%20of%20Bounds.png)

### Multiple Arrays

![Multiple Arrays](./images/5.5%20Multiple%20Arrays.png)

### Swapping Values

![Swapping Values](./images/5.6%20Swapping%20Values.png)

### 2D Arrays

![2D Arrays](./images/5.9%202D%20Arrays.png)

### Character Arrays

![Character Arrays](./images/5.10%20Character%20Arrays.png)
![Character Arrays Common Errors](<./images/5.10%20String%20Error%20(strcpy).png>)

### String Library <string.h>

![String Library 1](./images/5.11%20String%20Library%20%3Cstring.h%3E.png)
![String Library 2](./images/5.11%20String%20Function%20%3Cstring.h%3E.png)

### I/O: scanf vs fgets <stdio.h>

![I/O: scanf vs fgets](<./images/5.11%20User%20Input%20(scanf%20and%20fgets).png>)

### Type Checking and Conversion <ctype.h>

![Type Checking](./images/5.12%20Character%20Checking%20%3Cctype.h%3E.png)
![Type Conversion](./images/5.12%20Character%20Conversion%20%3Cctype.h%3E.png)

### Arrays and Strings (Example)

![Arrays and Strings (Example)](./images/5.13%20Arrays%20and%20Strings.png)

### Annual Salary (Example)

![Annual Salary (Example)](./images/5.14%20Example.png)

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

[Back to top](#table-of-contents)
