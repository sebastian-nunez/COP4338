# Chapter 4: Loops, Scope and Enums

- [Chapter 4: Loops, Scope and Enums](#chapter-4-loops-scope-and-enums)
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

## While Loops

![While Loops](./4.2%20While%20Loops.png)

## For Loops

![For Loops](./4.4%20For%20Loops.png)
![For Loops](./4.4%20For%20Loop%20Styling.png)

## Pre vs Post Operators

![Pre vs Post Operators](./4.4%20Pre%20vs%20Post%20Increment.png)

## Do-While Loops

![Do-While Loops](./4.6%20Do-While%20Loops.png)

## Loops and Strings

![Loops and Strings](./4.7%20Loops%20and%20Strings.png)

## Nested Loops

![Nested Loops](./4.8%20Nested%20Loops.png)

## Break Statement

![Break Statement](./4.10%20Break%20Statement.png)

## Continue Statement

![Continue Statement](./4.10%20Continue%20Statement.png)

## Loop Indexing

![Loop Indexing](./4.11%20Loop%20Index.png)

## Variable Scope

![Variable Scope](./4.11%20Variable%20Scope.png)

## Enums

![Enums](./4.12%20Enums.png)

## Enums Example

![Enums Example](./4.12%20Enum%20Example.png)

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
