// calculates if first is multiple of the second
#include <stdio.h>
int main(void)
{
    int value1, value2;

    puts("Enter first value");
    scanf("%d", &value1);

    puts("Enter second value");
    scanf("%d", &value2);

    if (value1 % value2 == 0)
    {
        printf("%d is multiple of %d", value1, value2);
    }
    else
    {
        printf("%d is not multiple of %d", value1, value2);
    }
}