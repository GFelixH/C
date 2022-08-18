/*
8.15 (Displaying a Sentence with Its Words Reversed) Write a program that inputs a line of text,
tokenizes the line with function strtok and outputs the tokens in reverse order.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char base[100] = "";
    char *strToken;
    char tokens[] = " .";
    char *tokenized[50] = {NULL};
    size_t counter = 0;

    puts("Insert phrase");
    fgets(base, 99, stdin);

    base[strcspn(base, "\n")] = 0;

    strToken = strtok(base, tokens);
    counter++;
    for (size_t i = 0; strToken != NULL; i++)
    {
        tokenized[i] = strToken;
        counter++;
        strToken = strtok(NULL, tokens);
    }
    for (int i = counter - 2; i >= 0; i--)
    {
        printf("%s ", tokenized[i]);
    }
    return 0;
}