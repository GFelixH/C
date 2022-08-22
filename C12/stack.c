#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *nextNode;
};
typedef struct node node;

int pop(node **topPtr);
void push(node **topPtr, int value);
void printStack(node *streamPtr);

int main(void)
{
    node *stack = NULL;
    printStack(stack);
    pop(&stack);
    push(&stack, 1);
    printStack(stack);
    push(&stack, 1);
    printStack(stack);
    push(&stack, 2);
    printStack(stack);
    push(&stack, 3);
    printStack(stack);
    push(&stack, 1);
    printStack(stack);
    pop(&stack);
    printStack(stack);
    pop(&stack);
    printStack(stack);
    pop(&stack);
    printStack(stack);
    pop(&stack);
    printStack(stack);
    return 0;
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
            printf("%d --> ", streamPtr->value);
            streamPtr = streamPtr->nextNode;
        }
        puts("NULL");
    }
}
int pop(node **topPtr)
{
    if (*topPtr != NULL)
    {
        node *tempPtr = malloc(sizeof(node));
        if (tempPtr != NULL)
        {
            tempPtr = *topPtr;
            int popValue = (*topPtr)->value;
            *topPtr = (*topPtr)->nextNode;
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
void push(node **topPtr, int value)
{
    node *tempPtr = malloc(sizeof(node));

    if (tempPtr != NULL)
    {
        tempPtr->value = value;
        tempPtr->nextNode = *topPtr;
        *topPtr = tempPtr;
    }
    else
    {
        puts("NO MEMORY");
    }
}