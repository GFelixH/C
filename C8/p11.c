/*
8.15 (Displaying a Sentence with Its Words Reversed)
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100] = "";
    char *pointers[100] = {NULL};
    char *mPtr = NULL;
    int i = 0;

    fgets(string, 100, stdin);

    mPtr = strtok(string, " \n");

    while (mPtr != NULL)
    {
        puts(mPtr);
        pointers[i] = mPtr;
        i++;
        mPtr = strtok(NULL, " \n");
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%s ", pointers[j]);
    }
    return 0;
}