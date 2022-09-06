// Given numRows and numColumns, print a list of all seats in a theater. Rows are numbered, columns lettered, as in 1A or 3E. Print a space after each seat, including after the last. Ex: numRows = 2 and numColumns = 3 prints:
// 1A 1B 1C 2A 2B 2C

#include <stdio.h>

int main(void) {
    int numRows;
    int numColumns;
    int currentRow;
    int currentColumn;
    char currentColumnLetter;

    scanf("%d", &numRows);
    scanf("%d", &numColumns);

    /* Your solution goes here  */
    for (int row = 1; row <= numRows; row++) {
        currentColumnLetter = 'A';
        for (int col = 0; col < numColumns; col++) {
            printf("%d%c ", row, currentColumnLetter);
            currentColumnLetter++;
        }
    }

    printf("\n");

    return 0;
}
