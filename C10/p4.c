/*
10.8 (Using Unions) Create union integer with members char c, short s, int i and long b.
Write a program that inputs values of type char, short, int and long and stores the values in union
variables of type union integer. Each union variable should be printed as a char, a short, an int
and a long. Do the values always print correctly?
*/
#include <stdio.h>

int main(void)
{
    union integer
    {
        char c;
        short int s;
        int i;
        long int b;
    } myInteger;
    scanf("%c%hd%d%ld", &myInteger.c, &myInteger.s, &myInteger.i, &myInteger.b);
    printf("%c %hd %d %ld", myInteger.c, myInteger.s, myInteger.i, myInteger.b);
    // stores last data entered
    return 0;
}