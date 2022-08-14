/*
(Lowest Common Multiple) The lowest common multiple (LCM) of two integers is the smallest positive integer that is a multiple of both numbers. Write a function lcm that returns the lowest
common multiple of two numbers.
*/

#include <stdio.h>
#include <stdbool.h>

int lmc(int a, int b);

int main(void)
{

    // get numbers
    // minimun possible = bigger number
    // maxium possible = product of both
    // set range minimum maximum for x
    // multiple if x % value == 0;
    // print results

    int a, b;

    puts("Insert 2 integer values:");

    scanf("%d %d", &a, &b);

    // a is the biggest
    if (b > a)
    {
        int temp = b;
        b = a;
        a = temp;
    }

    int i = lmc(a, b);

    printf("The LCM is %d\n", i);
}
// return LMC of 2 integers
// condition: a >= b
int lmc(int a, int b)
{
    for (int i = a; i <= a * b; i++)
    {
        int remainder1 = i % a;
        int remainder2 = i % b;
        bool isMultiple = remainder1 == 0 && remainder2 == 0;
        if (isMultiple)
        {
            return i;
        }
    }
}