/*
13.10 (Totaling an Array’s Contents) Write a program that defines and uses macro SUMARRAY to
sum the values in a numeric array. The macro should receive the array and the number of elements
in the array as arguments
*/
#include <stdio.h>
#define SUMARRAY(array, size) ({   \
    int sum = 0;                   \
    for (int i = 0; i < size; i++) \
    {                              \
        sum += array[i];           \
    }                              \
    sum;                           \
})

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    printf("%d", SUMARRAY(array, 5));
    return 0;
}