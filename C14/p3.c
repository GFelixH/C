/*
14.4 (Sorting Integers) Write a program that sorts an array of integers into ascending or descending order. Use command-line arguments to pass either argument -a for ascending order or -d for
descending order. [Note: This is the standard format for passing options to a program in UNIX.]
*/
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int array[5] = {1, 4, 74, -8, 45};

    if (!strcmp(argv[1], "a"))
    {
        for (int i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 5 - i; j++)
            {
                if (array[j + 1] < array[j])
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 5 - i; j++)
            {
                if (array[j + 1] > array[j])
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}