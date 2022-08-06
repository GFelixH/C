// Separa Digitos
#include <stdio.h>
#include <limits.h>

void printaDigitos(long long int a, unsigned int c);
unsigned int calculaDigitos(long long int a);
long long int potenciaDez(unsigned int a);

int main(void)
{

    long long int a;
    printf("int %lld lint %lld, llint%lld\n", INT_MAX, LONG_MAX, LLONG_MAX);
    unsigned int c;
    scanf("%d", &a);
    c = calculaDigitos(a);
    printf("%d \n", c);
    printaDigitos(a, c);

    return 0;
}
void printaDigitos(long long int a, unsigned int c)
{
    while (c > 1)
    {
        long long int potDez = potenciaDez(c);
        printf("%d ", a / potDez);
        a %= potDez;
        c--;
    }
    // c = 1;
    printf("%d", a);
}
long long int potenciaDez(unsigned int a)
{
    long long int b = 1;
    for (int i = 0; i < a - 1; i++)
    {
        b *= 10;
    }
    return b;
}
unsigned int calculaDigitos(long long int a)
{
    unsigned int c = 0;
    if (a != 0)
    {
        while (a)
        {
            a /= 10;
            c++;
        }
        printf("c a ser devolvido %d \n", c);
    }
    else
    {
        c = 1;
        printf("c a ser devolvido %d \n", c);
        return c;
    }
    return c;
}