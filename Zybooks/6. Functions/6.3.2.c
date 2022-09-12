// Define stubs for the functions called by the below main(). Each stub should
// print "FIXME: Finish FunctionName()" followed by a newline, and should return
// -1. Example output:
// FIXME: Finish GetUserNum()
// FIXME: Finish GetUserNum()
// FIXME: Finish ComputeAvg()
// Avg: -1

#include <stdio.h>

/* Your solution goes here  */
int GetUserNum(void) {
    printf("FIXME: Finish GetUserNum()\n");
    return -1;
}

int ComputeAvg(int iNum1, int iNum2) {
    printf("FIXME: Finish ComputeAvg()\n");
    return -1;
}

int main(void) {
    int userNum1;
    int userNum2;
    int avgResult;

    userNum1 = GetUserNum();
    userNum2 = GetUserNum();

    avgResult = ComputeAvg(userNum1, userNum2);

    printf("Avg: %d\n", avgResult);

    return 0;
}
