/*
13.6 (Smallest of Two Numbers) Write a program that defines and uses macro MINIMUM2 to determine the smallest of two numeric values. Input the values from the keyboard.
*/
#include <stdio.h>
#define MINIMUM2(x, y) ((x > y) ? y : x)
int main(void)
{
    int a, b;
    puts("INSERT 2 INTEGERS");
    scanf("%d %d", &a, &b);
    int result;
    result = MINIMUM2(a, b);
    printf("%d\n", result);

    return 0;
}