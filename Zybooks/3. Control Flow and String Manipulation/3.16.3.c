// Using a conditional expression, write a statement that increments numUsers if
// updateDirection is 1, otherwise decrements numUsers. Ex: if numUsers is 8 and
// updateDirection is 1, numUsers becomes 9; if updateDirection is 0, numUsers
// becomes 7.

// Hint: Start with "numUsers = ...".

#include <stdio.h>

int main(void) {
    int numUsers;
    int updateDirection;

    scanf("%d", &numUsers);
    scanf("%d", &updateDirection);

    /* Your solution goes here  */
    numUsers += (updateDirection == 1) ? 1 : -1;

    printf("New value is: %d\n", numUsers);

    return 0;
}
