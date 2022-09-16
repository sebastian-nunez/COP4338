#include <stdio.h>

/*This program shall count the number of ocurrences of each digit entered;
   additionally, it will count the number of whitespace characters (could be an
   *SPACE*, newline or tab). Laslty, the program will count the number of
   "Other" characters entered*/
int main() {
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; i++)
    ndigit[i] = 0;

  c = getchar();
  while (c != EOF) {
    if (c >= '0' && c <= '9')
      ndigit[c - '0']++;
    else if (c == ' ' || c == '\n' || c == '\t')
      nwhite++;
    else
      nother++;

    c = getchar();
  }

  printf("digits =");
  for (i = 0; i < 10; i++)
    printf(" %d", ndigit[i]);

  printf(", white space = %d, other = %d\n", nwhite, nother);

  return 0;
}
