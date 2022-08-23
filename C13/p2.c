/*
(Adding Two Numbers) Write a program that defines macro SUM with two arguments, x and
y, and use SUM to produce the following output:
The sum of x and y is 13
*/
#include <stdio.h>
#define SUM(x, y) (printf("The sum of %d and %d is %d\n", x, y, x + y))
int main(void)
{
    SUM(1, 2);
    SUM(2, 3);
    SUM(4, 1);

    return 0;
}