/*
Fibonacci non-recursive
*/
#include <stdio.h>

unsigned long long int fibonacci(unsigned int position);

int main(void)
{
    unsigned int myPosition;

    scanf("%ud", &myPosition);

    printf("Fibonacci number: %llu\n", fibonacci(myPosition));
}
unsigned long long int fibonacci(unsigned int position)
{

    unsigned int d1 = 0, d2 = 1;
    unsigned long long int fiboNumber = 0;

    if (position == 1)
    {
        return d1;
    }
    else if (position == 2)
    {
        return d2;
    }
    else
    {
        for (unsigned int i = 3; i <= position; i++)
        {
            fiboNumber = d1 + d2;
            d1 = d2;
            d2 = fiboNumber;
        }
        return fiboNumber;
    }
}