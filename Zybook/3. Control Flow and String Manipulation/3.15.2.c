// Replace any alphabetic character with '_' in 2-character string passCode. Ex:
// If passCode is "9a", output is: 9_ Hint: Use two if statements to check each
// of the two characters in the string, using isalpha().

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char passCode[3];

    scanf("%s", passCode);

    /* Your solution goes here  */
    if (isalpha(passCode[0])) passCode[0] = '_';
    if (isalpha(passCode[1])) passCode[1] = '_';

    printf("%s\n", passCode);
    return 0;
}
