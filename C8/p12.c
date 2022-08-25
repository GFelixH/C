/*
8.16 (Searching for Substrings)
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100] = "";
    char substring[100] = "";
    char *searchPtr = NULL;

    fgets(string, 100, stdin);
    fgets(substring, 100, stdin);

    string[strlen(string) - 1] = '\0';
    substring[strlen(substring) - 1] = '\0';

    searchPtr = strstr(string, substring);
    puts(string);
    while (searchPtr != NULL)
    {
        puts(searchPtr);
        searchPtr = strstr(searchPtr + 1, substring);
    }
    return 0;
}