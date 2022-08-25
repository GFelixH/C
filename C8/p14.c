/*
8.18 (Counting Occurrences of Various Characters in a String) Write a program that inputs a
line of text and counts the total numbers of vowels, consonants, digits and white spaces in the given
line of text.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100] = "";
    char *searchPtr = NULL;
    int vowel = 0, consonants = 0, digits = 0, whiteSpaces = 0;

    fgets(string, 100, stdin);

    string[strlen(string) - 1] = '\0';

    puts(string);
    searchPtr = &string;
    while (*searchPtr != '\0')
    {
        puts(searchPtr);
        searchPtr = searchPtr + 1;
    }
    // printf("COUNTER : %d", counter);
    return 0;
}