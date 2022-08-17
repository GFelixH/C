/*
8.13 (Pig Latin) Write a program that encodes English-language phrases into pig Latin. Pig Latin is a form of coded language often used for amusement.
*/
#include <stdio.h>
#include <string.h>

void swap(char *const a, char *const b);
void firstToLast(char *base);
void addsAy(char *base);
void addsSpace(char *base);
void pigLatim(char *const base);
void removeEnter(char *base);

int main(void)
{
    char s1[100] = "";

    puts("Insert text to be translated to Pig Latim:");
    fgets(s1, 99, stdin);

    removeEnter(s1);
    pigLatim(s1);
    puts(s1);

    // char s2[] = "Test";
    // pigLatim(s2);
    // puts(s2);

    return 0;
}
void removeEnter(char *base)
{
    char *ptr = NULL;
    int endline = (int)'\n';

    ptr = strchr(base, endline);
    *ptr = '\0';
}
void pigLatim(char *base)
{
    char myTokens[100] = "";
    char *tokenPtr = strtok(base, " ");

    while (tokenPtr != NULL)
    {
        char temp[100] = "";
        strcpy(temp, tokenPtr);
        firstToLast(temp);
        addsAy(temp);
        addsSpace(temp);
        strcat(myTokens, temp);
        tokenPtr = strtok(NULL, " ");
    }
    strcpy(base, myTokens);
}
void addsSpace(char *base)
{
    char s[] = " ";
    base = strcat(base, s);
}
void addsAy(char *base)
{
    char s[] = "ay";
    base = strcat(base, s);
}
void swap(char *const a, char *const b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void firstToLast(char *base)
{
    size_t size = strlen(base);
    char myString[size];

    myString[size + 1] = base[0];
    for (size_t i = 0; i < size - 1; i++)
    {
        myString[i] = base[i + 1];
    }
    myString[size - 1] = base[0];
    myString[size] = '\0';
    strcpy(base, myString);
}