/*
8.10 (Appending Part of a String) Write a program that uses function strncat to append part
of a string to another string. The program should input the strings, and the number of characters
to be appended, then display the first string and its length after the second string was appended.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    const size_t size = 100;
    char s1[size], s2[size];
    size_t number;

    fgets(s1, size - 1, stdin);
    fgets(s2, size - 1, stdin);

    puts("Insert number of characters to be appended: ");
    scanf("%u", &number);

    printf("First String: %s\nString length:%u\n", s1, strlen(s1));

    char *newline;
    int c = '\n';
    newline = strchr(s1, c);
    *newline = '\0';

    strncat(s1, s2, number);

    printf("Appended: %s\nLength:%u", s1, strlen(s1));
    return 0;
}