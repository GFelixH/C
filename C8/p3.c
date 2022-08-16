/*
Displaying Strings in Alternating Uppercase and Lowercase) Write a program that inputs
a line of text into char array s[100]. Output the line in alternate uppercase letters and lowercase letters.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char s[100];

    fgets(s, 99, stdin);
    char *charStream = s;
    size_t len = strlen(s);

    for (size_t i = 0; i < len; i++)
    {
        char c = *charStream;
        if (i % 2 == 0)
        {
            printf("%c", toupper(c));
        }
        else
        {
            printf("%c", tolower(c));
        }
        charStream = charStream + 1;
    }

    return 0;
}