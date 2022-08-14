/*
(Selection Sort) A selection sort algorithm for a one-dimensional array has the following steps:
a) The smallest value in the array is found.
b) It is swapped with the value in the first position of the array.
c) The above steps are repeated for the rest of the array starting at the second position and
advancing each time.
Eventually the entire array is divided into two parts: the sub-array of items already sorted
which is built up from left to right and is found at the beginning, and the sub-array of
items remaining to be sorted, occupying the remainder of the array. Write a program
that sorts an array of 10 integers using this algorithm.
*/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int myArray[10] = {1, 9, 8, 7, 6, 6, 4, 5, 46, -1};
    int minIndex, temp;
    bool swapValues = false;

    // Display Array
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myArray[i]);
    }
    puts(" ");

    for (int j = 0; j < 10; j++) // Entire Array
    {
        // Initializes comparator to current array position
        int comparator = myArray[j];
        // Find smallest value
        for (int i = j; i < 10; i++)
        {
            if (myArray[i] < comparator)
            {
                comparator = myArray[i];
                minIndex = i;
                swapValues = true;
            }
        }
        // Swap values
        if (swapValues)
        {
            printf("Swaping %d <-> %d\n", myArray[j], myArray[minIndex]);
            temp = myArray[j];
            myArray[j] = myArray[minIndex];
            myArray[minIndex] = temp;
            swapValues = false;
            // Display Array
            for (int i = 0; i < 10; i++)
            {
                printf("%d ", myArray[i]);
            }
            puts(" ");
        }
    }

    // Display Array
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myArray[i]);
    }
    puts(" ");
}