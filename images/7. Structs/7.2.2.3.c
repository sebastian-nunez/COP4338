// Define a function SetBirth, with int parameters monthVal and dayVal, that
// returns a struct of type BirthMonthDay. The function should assign
// BirthMonthDay's data member numMonths with monthVal and numDays with dayVal.

#include <stdio.h>

typedef struct BirthMonthDay_struct {
  int numMonths;
  int numDays;
} BirthMonthDay;

/* Your code goes here */
BirthMonthDay SetBirth(int monthVal, int dayVal) {
  BirthMonthDay temp = {monthVal, dayVal};
  return temp;
}

int main(void) {
  BirthMonthDay myBirthday;
  int monthVal;
  int dayVal;

  scanf("%d", &monthVal);
  scanf("%d", &dayVal);

  myBirthday = SetBirth(monthVal, dayVal);

  printf("I was born on %d/%d.\n", myBirthday.numMonths, myBirthday.numDays);

  return 0;
}
