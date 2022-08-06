#include <stdio.h>
/*
(Triangle-Printing Program) Write a program that prints the following patterns separately,
one below the other. Use for loops to generate the patterns. All asterisks (*) should be printed by a single printf statement of the form printf("%s", "*"); (this causes the asterisks to print side by
side). [Hint: The last two patterns require that each line begin with an appropriate number of
blanks.]

10 retangulo
*/
int main(void)
{
    // 1
    // iterar linhas
    for (int i = 1; i < 11; i++)
    {
        // printar i *
        for (int j = 1; j <= i; j++)
        {
            printf("%s", "*");
        }
        puts(" ");
    }
    puts(" ");
    // 2
    //  iterar linhas
    for (int i = 10; i > 0; i--)
    {
        // printar i *
        for (int j = 1; j <= i; j++)
        {
            printf("%s", "*");
        }
        puts(" ");
    }
    puts(" ");
    // 3
    //  iterar linhas
    for (int i = 10; i > 0; i--) //[10,1]
    {
        char s1[10] = {" "};
        // adicionar i *
        for (int j = 0; j < i - 1; j++) //[1,10][1,9]
        {
            s1[j] = '*';
        }
        printf("%10s\n", s1);
    }
    puts(" ");
    // 4
    //  iterar linhas
    for (int i = 1; i <= 10; i++)
    {
        char s1[10] = {" "};
        // printar i *
        for (int j = 0; j < i - 1; j++)
        {
            s1[j] = '*';
        }
        printf("%10s\n", s1);
    }
    system("pause");
    return 0;
}