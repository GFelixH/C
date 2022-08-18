/*
9.14 (Outputting a Number with the Floating-Point Conversion Specifiers) Write a program
that uses each of the conversion specifiers e, f and g to input the value 1.2345. Print the values of
each variable to prove that each conversion specifier can be used to input this same value.
*/
#include <stdio.h>
int main(void)
{
    double b;

    scanf("%e", &b);
    printf("%e %f %g", b, b, b);
    scanf("%f", &b);
    printf("%e %f %g", b, b, b);

    scanf("%g", &b);
    printf("%e %f %g", b, b, b);

    return 0;
}