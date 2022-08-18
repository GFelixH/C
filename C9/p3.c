/*
9.8 (Printing Numbers in Various Field Widths) Write a program to test the results of printing
the integer value 12345 and the floating-point value 1.2345 in fields of various sizes. What happens
when the values are printed in fields containing fewer digits than the values?
*/
#include <stdio.h>
int main(void)
{
    int a = 12345;
    float b = 1.2345;

    printf("%10d %10f\n", a, b);

    return 0;
}