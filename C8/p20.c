/*
8.24 (Strings Ending with "tion") Write a program that reads a series of strings and prints only
those that end with the letters "tion".
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    char strings[4][100] = {
        "Ociantion",
        "tionBoqueirao",
        "Aviaioncaoion",
        "Tupition",
    };
    char find[] = "tion";
    int size = 4;

    for (int i = 0; i < size; i++)
    {
        char *firstPosition = &strings[i][strlen(strings[i]) - 4];
        char *position = strstr(strings[i], find);
        if (firstPosition == position)
        {
            puts(strings[i]);
        }
    }
    return 0;
}