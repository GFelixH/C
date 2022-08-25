/*
8.19 (Removing a Particular Word From a Given Line of Text)
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100] = "Test test remove this is a test remove this";
    char substring[100] = " ";
    char removeString[100] = "remove";
    char resultString[100] = "";
    char *searchPtr = NULL;
    int counterBefore = 0, counterAfter = 0;

    // fgets(string, 100, stdin);
    // fgets(substring, 100, stdin);

    // string[strlen(string) - 1] = '\0';
    // substring[strlen(substring) - 1] = '\0';
    // removeString[strlen(removeString) - 1] = '\0';

    searchPtr = strtok(string, substring);
    while (searchPtr != NULL)
    {
        int x = strcmp(searchPtr, removeString);
        if (!x)
        {
            counterAfter--;
        }
        else
        {
            strcat(resultString, searchPtr);
        }
        counterBefore++;
        searchPtr = strtok(NULL, substring);
    }
    counterAfter += counterBefore;
    puts(resultString);
    printf("COUNTER : %d", counterBefore);
    printf("COUNTER : %d", counterAfter);
    return 0;
}