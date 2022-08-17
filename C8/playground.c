#include <stdio.h>
#include <string.h>
void swap(char *const a, char *const b);
void firstToLast(char *base);
void addsAy(char *base);
void addsSpace(char *base);

int main(void)
{
    char s1[] = "Test";

    char myTokens[100];

    char *tokenPtr = strtok(s1, " ");

    while (tokenPtr != NULL)
    {
        char temp[100];
        strcpy(temp, tokenPtr);
        firstToLast(temp);
        addsAy(temp);
        addsSpace(temp);
        strcat(myTokens, temp);
        tokenPtr = strtok(NULL, " ");
    }
    puts(myTokens);

    return 0;
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
    for (int i = 0; i < size - 1; i++)
    {
        myString[i] = base[i + 1];
    }
    myString[size - 1] = base[0];
    myString[size] = '\0';
    strcpy(base, myString);
}