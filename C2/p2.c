#include <stdio.h>

int main(void)
{

    int input;

    puts("Enter 5 digit number");

    scanf("%d", &input);

    printf("\a%d %d %d %d %d", input / 10000, input / 1000 % 10, input / 100 % 10, input / 10 % 10, input % 10);
    return 0;
}