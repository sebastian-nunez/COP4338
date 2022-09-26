/**
 * Pointers Class Activity
 * 09/26/22
 * Sebastian Nunez (6358289)
 */
#include <memory.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  char character;
  int integer;
  char string[100];
  double floatingPoint;

  printf("Enter a single character :: ");
  scanf("%c", &character);

  printf("Enter an integer :: ");
  scanf("%d", &integer);

  printf("Enter a string of characters :: ");
  scanf("%s", string);

  printf("Enter an floating point number :: ");
  scanf("%lf", &floatingPoint);

  char* pCharacter = &character;
  int* pInteger = &integer;
  char* pString = string;
  double* pFloatingPoint = &floatingPoint;

  printf("Character: %c\n", *pCharacter);
  printf("Integer: %d\n", *pInteger);
  printf("String: %s\n", pString);
  printf("Floating Point: %lf\n", *pFloatingPoint);

  printf("Character Pointer: %p\n", pCharacter);
  printf("Integer Pointer: %p\n", pInteger);
  printf("String Pointer: %p\n", pString);
  printf("Floating Point Pointer: %p\n", pFloatingPoint);

  return 0;
}
