/*
8.17 (Counting the Occurrences of a Substring) Write a program based on the program of
Exercise 8.16 that inputs several lines of text and a search string and uses function strstr to determine the total occurrences of the string in the lines of text. Print the result
*/
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
    int counter = 0;

    fgets(string, 100, stdin);
    fgets(substring, 100, stdin);

    string[strlen(string) - 1] = '\0';
    substring[strlen(substring) - 1] = '\0';

    puts(string);
    searchPtr = strstr(string, substring);
    while (searchPtr != NULL)
    {
        counter++;
        puts(searchPtr);
        searchPtr = strstr(searchPtr + 1, substring);
    }
    printf("COUNTER : %d", counter);
    return 0;
}