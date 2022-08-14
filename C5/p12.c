/*
Fibonacci) The Fibonacci series
0, 1, 1, 2, 3, 5, 8, 13, 21, …
begins with the terms 0 and 1 and has the property that each succeeding term is the sum of the two
preceding terms. a) Write a nonrecursive function fibonacci(n) that calculates the nth Fibonacci
number. Use unsigned int for the function’s parameter and unsigned long long int for its return
type. b) Determine the largest Fibonacci number that can be printed on your system
*/
#include <stdio.h>
#include <limits.h>

unsigned long long fibonacci(unsigned int n);

int main(void)
{
    // Calculate fibonacci number given the position
    // unsigned int p;

    // puts("Insert position to be calculated:");
    // scanf("%ud", &p);

    // unsigned long long result = fibonacci(p);
    // printf("%llu", result);

    // Calculate larggest fibonacci number
    int x = 1;
    while (x)
    {
        unsigned long long result = fibonacci(x);
        printf("%d  %llu \n", x, result);
        x++;
    }
}
unsigned long long fibonacci(unsigned int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
