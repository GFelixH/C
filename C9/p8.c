/*
9.13 (Reading an Integer with Each scanf Conversion Specifier) Write a program that inputs the
value 437 using each of the scanf integer conversion specifiers. Print each input value using all the
integer conversion specifiers.
*/
#include <stdio.h>
int main(void)
{
    int a;
    scanf("%d", &a);
    printf("%d %u %o %x\n", a, a, a, a);
    scanf("%u", &a);
    printf("%d %u %o %x\n", a, a, a, a);
    scanf("%o", &a);
    printf("%d %u %o %x\n", a, a, a, a);
    scanf("%x", &a);
    printf("%d %u %o %x\n", a, a, a, a);

    return 0;
}