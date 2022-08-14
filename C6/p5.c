/*
(Intersection of Sets) Use one-dimensional arrays to solve the following problem. Read in
two sets of numbers, each having 10 numbers. After reading all values, display the unique elements
common to both sets of numbers.
*/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int array1[10] = {5, 12, 23456, 3, 41, -1, -109, 49, 20, 10};
    int array2[10] = {5, 12, 123, 3, 12343, -1, 567346, 49, 20, 10};
    int intersectionArray[10] = {0};
    int counter = 0;

    for (int i = 0; i < 10; i++)
    {
        int current = array1[i];
        bool include = false;

        for (int j = 0; j < 10; j++)
        {
            int compare = array2[j];
            if (compare == current)
            {
                include = true;
            }
        }
        if (include)
        {
            intersectionArray[counter] = array1[i];
            counter++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", intersectionArray[i]);
    }
    puts(" ");
}