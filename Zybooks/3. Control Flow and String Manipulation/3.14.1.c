// Assign the size of userInput to stringSize. Ex: if userInput is "Hello",
// output is: Size of userInput: 5

#include <stdio.h>
#include <string.h>

int main(void) {
  char userInput[50];
  int stringSize;

  scanf("%s", userInput);

  /* Your solution goes here  */
  stringSize = strlen(userInput);

  printf("Size of userInput: %d\n", stringSize);

  return 0;
}
