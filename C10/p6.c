/*
10.10 (Right Shifting Integers) Write a program that right shifts an integer variable 4 bits. The
program should print the integer in bits before and after the shift operation. Does your system place
0s or 1s in the vacated bits?
*/
#include <stdio.h>
int main(void)
{
    struct test
    {
        unsigned int a : 5;
    } teste;
    teste.a = 15;
    teste.a >>= 1;
    printf("%d\n", teste.a);
    teste.a <<= 2;
    printf("%d\n", teste.a);
    return 0;
}