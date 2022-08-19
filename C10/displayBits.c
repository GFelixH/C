/*
10.15 (Portable displayBits Function) Modify function displayBits of Fig. 10.7 so it’s portable
between systems using 2-byte integers and systems using 4-byte integers. [Hint: Use the sizeof operator to determine the size of an integer on a particular machine.
*/
#include <stdio.h>
#include <limits.h>
void displayBits(unsigned int a);
void bitsInString(unsigned int a, char result[33]);
int main(void)
{
    unsigned int a = 1245132;
    displayBits(a);
    char result[33] = "";
    bitsInString(a, result);
    puts(result);
    return 0;
}
void displayBits(unsigned int a)
{
    unsigned int numberOfBits = CHAR_BIT * sizeof(unsigned int);
    unsigned int mask = 1 << (numberOfBits - 1);
    for (unsigned int i = 1; i <= numberOfBits; i++)
    {
        putchar(a & mask ? '1' : '0');
        a <<= 1;

        if (i % 8 == 0)
        {
            printf("%c", ' ');
        }
    }
}
void bitsInString(unsigned int a, char result[33])
{
    unsigned int numberOfBits = CHAR_BIT * sizeof(unsigned int);
    unsigned int mask = 1 << (numberOfBits - 1);
    for (unsigned int i = 1; i <= numberOfBits; i++)
    {
        result[i - 1] = (a & mask ? '1' : '0');
        a <<= 1;
    }
}