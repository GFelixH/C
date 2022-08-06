/*
(Perfect Numbers) An integer number is said to be a perfect number if its factors, including
1 (but not the number itself), sum to the number. For example, 6 is a perfect number because 6 =
1 + 2 + 3. Write a function isPerfect that determines whether parameter number is a perfect number. Use this function in a program that determines and prints all the perfect numbers between 1
and 1000. Print the factors of each perfect number to confirm that the number is indeed perfect.
Challenge the power of your computer by testing numbers much larger than 1000.
*/
#include <stdio.h>

int main(void)
{
    int max;
    scanf("%d", &max);
    int contadorPerfeitos = 0;
    for (int i = 2; i < max; i++)
    {
        int soma = 0;
        printf("Numero: %d\nFatores: ", i);
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                soma += j;
                printf("%d, ", j);
            }
        } // loop contagem fatores
        if (i != soma)
        {
            puts("Nao e perfeito");
        }
        else
        {
            puts("E perfeito!");
            contadorPerfeitos++;
        }
    } // loop numeros
    printf("Perfeitos entre 1 e %d = %d", max, contadorPerfeitos);
    return 0;
}