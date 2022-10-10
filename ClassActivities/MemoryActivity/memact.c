#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char* pChar = (char*)malloc(sizeof(char));
  int* pInt = (int*)malloc(sizeof(int));
  char* pString = (char*)malloc(6 * sizeof(char));
  double* pDouble = (double*)malloc(sizeof(double));
  int* pArray = (int*)malloc(10 * sizeof(int));

  if (pChar == NULL) {
    printf("Unable to allocate memory for pChar\n");
    return 1;
  }
  if (pInt == NULL) {
    printf("Unable to allocate memory for pInt\n");
    return 1;
  }
  if (pString == NULL) {
    printf("Unable to allocate memory for pString\n");
    return 1;
  }
  if (pArray == NULL) {
    printf("Unable to allocate memory for pArray\n");
    return 1;
  }

  *pChar = 'E';
  *pInt = 25;

  pString[0] = 'N';
  pString[1] = 'u';
  pString[2] = 'n';
  pString[3] = 'e';
  pString[4] = 'z';
  pString[5] = '\0';

  *pDouble = 32.76;

  for (int i = 0; i < 10; i++) {
    pArray[i] = i;
  }

  printf("Character: %c\n", *pChar);
  printf("Integer: %d\n", *pInt);
  printf("String: %s\n", pString);
  printf("Float: %.2lf\n", *pDouble);

  printf("Array of Integers: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", pArray[i]);
  }
  printf("\n");

  free(pChar);
  free(pInt);
  free(pString);
  free(pDouble);
  free(pArray);

  return 0;
}
