/*
8.9 (Concatenating Strings) Write a program that uses function strcat to concatenate two
strings provided by the user. The program should print the strings before and after concatenating
as well as the length of the concatenated string.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    const size_t size = 100;
    char s1[size], s2[size];
    fgets(s1, size - 1, stdin);
    fgets(s2, size - 1, stdin);

    puts(s1);
    puts(s2);

    strcat(s1, s2);
    puts(s1);
    printf("%u", strlen(s1));
    return 0;
}