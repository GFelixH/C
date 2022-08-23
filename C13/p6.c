/*
(Printing an Array) Write a program that defines and uses macro PRINTARRAY to print an
array of integers. The macro should receive the array and the number of elements in the array as
arguments.
*/
#include <stdio.h>

#define PRINTARRAY(array, size)        \
    do                                 \
    {                                  \
        for (int i = 0; i < size; i++) \
        {                              \
            printf("%c ", array[i]);   \
        }                              \
    } while (0);

int main(void)
{
    char array[9] = "12345678";
    PRINTARRAY(array, 9);
    return 0;
}