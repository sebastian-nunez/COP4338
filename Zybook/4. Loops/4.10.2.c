// "Simon Says" is a memory game where "Simon" outputs a sequence of 10 characters (R, G, B, Y) and the user must repeat the sequence. Create a for loop that compares the two strings starting from index 0. For each match, add one point to userScore. Upon a mismatch, exit the loop using a break statement. Assume simonPattern and userPattern are always the same length. Ex: The following patterns yield a userScore of 4:
// simonPattern: RRGBRYYBGY
// userPattern:  RRGBBRYBGY
#include <stdio.h>
#include <string.h>

int main(void) {
    char simonPattern[50];
    char userPattern[50];
    int userScore;
    int i;

    userScore = 0;

    scanf("%s", simonPattern);
    scanf("%s", userPattern);

    /* Your solution goes here  */
    for (i = 0; i < strlen(simonPattern); i++) {
        if (simonPattern[i] == userPattern[i])
            userScore++;
        else
            break;
    }

    printf("userScore: %d\n", userScore);

    return 0;
}
