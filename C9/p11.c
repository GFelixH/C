/*
9.16 (Printing a Question Mark as a Character Constant) Write a program that determines
whether ? can be printed as the character constant '?' rather than the character constant escape sequence '\?' using conversion specifier %c in the format control string of a printf statement.
*/
#include <stdio.h>
int main(void)
{
    char s = '?';
    printf("%c", s);
    return 0;
}