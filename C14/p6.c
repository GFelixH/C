/*
14.7 (Command-Line Arguments) Write a program that takes two command-line arguments
that are filenames, reads the characters from the first file one at a time and writes the characters in
reverse order to the second file.
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    char value;
    struct node *nextPtr;
};
typedef struct node node;

char pop(node **topPtr);
void push(node **topPtr, char value);
void printStack(node *streamPtr);

int main(int argc, char *argv[])
{
    FILE *readPtr = fopen(argv[1], "r");
    FILE *writePtr = fopen(argv[2], "w");
    // FILE *readPtr = fopen("input.txt", "r");
    // FILE *writePtr = fopen("output.txt", "w");
    node *top = NULL;

    if (readPtr != NULL && writePtr != NULL)
    {
        char a;
        int i = 0;

        a = fgetc(readPtr);
        while (!feof(readPtr))
        {
            push(&top, a);
            a = fgetc(readPtr);
        }

        fclose(readPtr);

        printStack(top);

        while (top != NULL)
        {
            char b = pop(&top);
            fputc(b, writePtr);
        }
        fclose(writePtr);
    }
    else
    {
        puts("ERROR OPENING THE FILES");
    }
}
void printStack(node *streamPtr)
{
    if (streamPtr == NULL)
    {
        puts("LIST IS EMPTY");
    }
    else
    {
        puts("THE STACK IS");
        while (streamPtr != NULL)
        {
            printf("%c --> ", streamPtr->value);
            streamPtr = streamPtr->nextPtr;
        }
        puts("NULL");
    }
}
char pop(node **topPtr)
{
    if (*topPtr != NULL)
    {
        node *tempPtr = malloc(sizeof(node));
        if (tempPtr != NULL)
        {
            char popValue = (*topPtr)->value;
            *topPtr = (*topPtr)->nextPtr;
            free(tempPtr);
            return popValue;
        }
        else
        {
            puts("NO MEMORY");
        }
    }
    else
    {
        puts("LIST EMPTY");
    }
}
void push(node **topPtr, char value)
{
    node *tempPtr = malloc(sizeof(node));

    if (tempPtr != NULL)
    {
        tempPtr->value = value;
        tempPtr->nextPtr = *topPtr;
        *topPtr = tempPtr;
    }
    else
    {
        puts("NO MEMORY");
    }
}