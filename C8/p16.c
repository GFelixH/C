/*
8.20 (Counting the Number of Words in a String) Write a program that inputs several lines of
text and uses strtok to count the total number of words. Assume that the words are separated by
either spaces or newline characters.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100] = "";
    char *searchPtr = NULL;
    int c, words = 0, counter = 0;

    while ((c = getchar()) != EOF)
    {
        string[counter] = (char)c;
        counter++;
    }
    searchPtr = strtok(string, " \n");
    while (searchPtr != NULL)
    {
        words++;
        searchPtr = strtok(NULL, " \n");
    }
    printf("%d", words);
    return 0;
}