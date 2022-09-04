/*
 * C Program to Illustrate Pass by Value.
 */
#include <stdio.h>
 
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
 
int main()
{
    int num1 = 10, num2 = 20;
 
    printf("Before swapping num1 = %d num2 = %d\n", num1, num2);
    swap(num1, num2);
    printf("After swapping num1 = %d num2 = %d \n", num2, num1);
    return 0;
}