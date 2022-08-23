/*
14.6 (Dynamic Array Allocation) Write a program that dynamically allocates an array of integers. The size of the array should be input from the keyboard. The elements of the array should be
assigned values input from the keyboard. Print the values of the array. Next, reallocate the memory
for the array to half of the current number of elements. Print the values remaining in the array to
confirm that they match the first half of the values in the original array.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *myArray = calloc(6, sizeof(int));
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &myArray[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", myArray[i]);
    }
    myArray = realloc(myArray, 3 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", myArray[i]);
    }
    return 0;
}