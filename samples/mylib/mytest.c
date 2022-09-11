#include "mylib.h"
#include <stdio.h>

int main() {
    int x = myatoi("10");
    printf("x = %d\n", x);
    myprintf("this is a string");
    return 0;
}
