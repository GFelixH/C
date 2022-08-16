#include <stdio.h>
int main(void)
{
    int number, x;

    puts("Enter 5-digit number");

    scanf("%d", &number);

    x = number / 10000;
    number %= 10000;
    printf("%d ", x);
    x = number / 1000;
    number %= 1000;
    printf("%d ", x);
    x = number / 100;
    number %= 100;
    printf("%d ", x);
    x = number / 10;
    number %= 10;
    printf("%d %d", x, number);
}