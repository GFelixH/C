/*
(Union of Sets) Use one-dimensional arrays to solve the following problem. Read in two
sets of numbers, each having 10 numbers. After reading all values, display all the unique elements
in the collection of both sets of numbers. Use the smallest possible array to solve this problem.
*/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    /*
    Initialize 2 int arrays size 10
    select first element of array 1 and search for it in array2
    if not present include it in array union
    do the same with array 2 comparing with array 1
    smallest possible is union[20], when every element is unique
    or count number of unique found
    */

    int array1[10] = {5, 12, 23456, 3, 41, -1, -109, 49, 20, 10};
    int array2[10] = {5, 12, 123, 3, 12343, -1, 567346, 49, 20, 10};
    int unionArray[20] = {0};
    int counter = 0;

    for (int i = 0; i < 10; i++)
    {
        int current = array1[i];
        bool include = true;

        for (int j = 0; j < 10; j++)
        {
            int compare = array2[j];
            if (compare == current)
            {
                include = false;
            }
        }
        if (include)
        {
            unionArray[counter] = array1[i];
            counter++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        int current = array2[i];
        bool include = true;

        for (int j = 0; j < 10; j++)
        {
            int compare = array1[j];
            if (compare == current)
            {
                include = false;
            }
        }
        if (include)
        {
            unionArray[counter] = array2[i];
            counter++;
        }
    }
    // creates final array
    int finalUnion[counter];
    for (int i = 0; i <= counter; i++)
    {
        finalUnion[i] = unionArray[i];
    }
    // Display Array
    for (int i = 0; i < counter; i++)
    {
        printf("%d ", finalUnion[i]);
    }
    puts(" ");
}