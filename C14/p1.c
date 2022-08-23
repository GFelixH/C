/*
14.2 (Variable-Length Argument List: Calculating Products) Write a program that calculates the
product of a series of integers that are passed to function product using a variable-length argument
list. Test your function with several calls, each with a different number of arguments.
*/
#include <stdio.h>
#include <stdarg.h>
int sum(int size, ...);
int main(void)
{
    printf("%d ", sum(2, 5, 5));
    printf("%d ", sum(7, 5, 5, 5, 5, 5, 5, 5));
    printf("%d ", sum(2, 5, -5));
    printf("%d ", sum(2, -5, -5));
    return 0;
}
int sum(int size, ...)
{
    int sum = 0;
    va_list stream;
    va_start(stream, size);
    for (int i = 0; i < size; i++)
    {
        sum += va_arg(stream, int);
    }
    va_end(stream);
    return sum;
}