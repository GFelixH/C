/*
(Recursive Prime) Write a recursive function isPrime that determines whether the given
input is a prime number. Use this function in a program.
*/
#include <stdio.h>

int isPrime(int a);

int main(void)
{
    int a;
    scanf("%d", &a);

    if (isPrime(a) == 2)
    {
        puts("Is Prime");
    }
    else
    {
        puts("Is not prime");
    }
}
int isPrime(int a)
{
    int counter = 0;

    for (int i = a; i > 0; i--)
    {
        if (a % i == 0)
        {
            counter++;
        }
    }
    return counter;
}