/*
8.21 (Alphabetizing a List of Strings) Use the string-comparison functions and the techniques
for sorting arrays to write a program that alphabetizes a list of strings. Use the names of 10 or 15
towns in your area as data for your program.
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    char strings[4][100] = {
        "Ocian",
        "Boqueirao",
        "Aviacao",
        "Tupi",
    };
    char *before, *after;
    int size = 4;
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            before = strings[j];
            after = strings[j + 1];
            int result = strcmp(before, after);
            if (result < 0)
            {
                // s1 < s2 increasing order
            }
            else if (result > 0)
            {
                char temp[100] = "";
                strcpy(temp, strings[j + 1]);
                strcpy(strings[j + 1], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%s ", strings[i]);
    }
    return 0;
}