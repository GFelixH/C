/*
8.23 (Strings Starting with "Th") Write a program that reads a series of strings and prints only
those beginning with the letters "Th"
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    char strings[4][100] = {
        "ThOcian",
        "thBoqueirao",
        "ThAviacao",
        "TuThpi",
    };
    char find[] = "Th";
    int size = 4;

    for (int i = 0; i < size; i++)
    {
        char *firstPosition = &strings[i][0];
        char *position = strstr(strings[i], find);
        if (firstPosition == position)
        {
            puts(strings[i]);
        }
    }
    return 0;
}