/*
13.7 (Smallest of Three Numbers) Write a program that defines and uses macro MINIMUM3 to determine the smallest of three numeric values. Macro MINIMUM3 should use macro MINIMUM2 defined
in Exercise 13.6 to determine the smallest number. Input the values from the keyboard.
*/
#include <stdio.h>
#define MINIMUM2(x, y) ((x > y) ? y : x)
#define MINIMUM3(x, y, z) ((x > MINIMUM2(y, z)) ? MINIMUM2(y, z) : x);

int main(void)
{
    int a, b, c;
    puts("INSERT 3 INTEGERS");
    scanf("%d %d %d", &a, &b, &c);
    int result;
    result = MINIMUM3(a, b, c);
    printf("%d\n", result);

    return 0;
}