#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxlength);
void copy(char from[], char to[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if (max > 0)
        printf("The longest line entered was: %s (Length: %d)\n", longest, max);

    return 0;
}

int getLine(char line[], int maxlength)
{
    int c, i;

    for(i = 0; i < maxlength && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

void copy(char from[], char to[])
{
    int i = 0;
    while(from[i] != '\0') {
        to[i] = from[i];
        i++;
    }

}
