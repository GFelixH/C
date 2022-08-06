/*
(Sum of Digits) Write a function that takes an integer and returns the sum of its digits. For
example, given the number 7631, the function should return 17
*/
#include <stdio.h>

int main(void)
{
    /*
        Receber Numero
        Percorrer digitos
        Somar digitos
        printar resultado

        scanf
        while(x)
        acumulador += x%10
        x /= 10
        printf
    */
    int number;
    int soma = 0;
    scanf("%d", &number);
    while (number)
    {
        soma += number % 10;
        number /= 10;
    }
    printf("Soma digitos: %d", soma);
    return 0;
}