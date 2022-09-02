// Greedy algorithm
#include <stdio.h>
#include <stdlib.h>

int get_cents();
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    enum programStatus
    {
        STOP = 0,
        CONTINUE
    };
    enum programStatus myStatus = CONTINUE;
    while (myStatus)
    {
        int cents = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;
        char c;

        cents = get_cents();

        quarters = calculate_quarters(cents);
        cents -= quarters * 25;

        dimes = calculate_dimes(cents);
        cents -= dimes * 10;

        nickels = calculate_nickels(cents);
        cents -= nickels * 5;

        pennies = calculate_pennies(cents);
        cents -= pennies;

        if (cents != 0)
        {
            puts("ERROR : CHANGE ISN'T 0");
            exit(EXIT_FAILURE);
        }

        printf("QUARTERS: %d\nDIMES: %d\nNICKELS: %d\nPENNIES %d\n\n", quarters, dimes, nickels, pennies);
        puts("CONTINUE ? (y\\n)");
        fflush(stdin);
        scanf("%c[yn]", &c);
        if (c == 'n')
        {
            myStatus = STOP;
        }
    }
    return 0;
}
int get_cents()
{
    int response;
    do
    {
        printf("%s", "Insert Cents: ");
        fflush(stdin);
        scanf("%d", &response);
    } while (response < 0 || response > 99);
    return response;
}
int calculate_quarters(int cents)
{
    int n = 0;
    for (n; cents >= 25; n++, cents -= 25)
        ;
    return n;
}
int calculate_dimes(int cents)
{
    int n = 0;
    for (n; cents >= 10; n++, cents -= 10)
        ;
    return n;
}
int calculate_nickels(int cents)
{
    int n = 0;
    for (n; cents >= 5; n++, cents -= 5)
        ;
    return n;
}
int calculate_pennies(int cents)
{
    int n = 0;
    for (n; cents >= 1; n++, cents -= 1)
        ;
    return n;
}
