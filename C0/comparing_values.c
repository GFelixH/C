// Comparing Values
#include <stdio.h>
int main(void)
{
    int value1, value2;

    printf("%s", "Enter First Value: ");
    scanf("%d", &value1);

    printf("%s", "Enter Second Value: ");
    scanf("%d", &value2);

    printf("The sum of %d and %d is %d\n", value1, value2, value1 + value2);
    if (value1 > value2)
    {
        printf("%d is bigger than %d", value1, value2);
    }
    else if (value1 == value2)
    {
        printf("%d is equal to %d", value1, value2);
    }
    else
    {
        printf("%d is bigger than %d", value2, value1);
    }
}
