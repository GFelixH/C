/*
(Concatenating Lists) Write a program that concatenates two linked lists of characters. The
program should include function concatenate that takes pointers to both lists as arguments and
concatenates the second list to the first list.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char value;
    struct node *nextPtr;
};
typedef struct node node;

void printLinkedList(node *streamPtr);
void insert(node **start, char value);
void concatenate(node **firstList, node **secondList);

int main(void)
{
    node *first = NULL;
    node *second = NULL;
    insert(&first, 'a');
    insert(&first, 'b');
    insert(&first, 'c');
    printLinkedList(first);
    insert(&second, 'd');
    insert(&second, 'e');
    insert(&second, 'f');
    insert(&second, 'g');
    printLinkedList(second);
    concatenate(&first, &second);
    printLinkedList(first);
    return 0;
}
void concatenate(node **firstList, node **secondList)
{
    node *current = *firstList;
    node *previous = NULL;

    while (current != NULL)
    {
        previous = current;
        current = current->nextPtr;
    }
    previous->nextPtr = *secondList;
}
void printLinkedList(node *streamPtr)
{
    if (streamPtr != NULL)
    {
        puts("THE LIST IS");
        while (streamPtr != NULL)
        {
            printf("%c --> ", streamPtr->value);
            streamPtr = streamPtr->nextPtr;
        }
        puts("NULL");
    }
    else
    {
        puts("LIST IS EMPTY");
    }
}
void insert(node **start, char value)
{
    node *newNodePtr = malloc(sizeof(node));

    if (newNodePtr != NULL)
    {
        newNodePtr->value = value;
        newNodePtr->nextPtr = NULL;

        node *currentNodePtr = *start; // search current as first
        node *previusNodePtr = NULL;   // search previus is NULL

        while (currentNodePtr != NULL && value > currentNodePtr->value)
        {
            // walk through the linked list
            // > sets the order : increasing order
            previusNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->nextPtr;
        }

        if (previusNodePtr == NULL)
        { // first node or before first node
            newNodePtr->nextPtr = *start;
            *start = newNodePtr;
        }
        else
        {
            // not in the first node, could be the last
            previusNodePtr->nextPtr = newNodePtr;
            newNodePtr->nextPtr = currentNodePtr;
        }
    }
    else
    {
        puts("Memory not available.\n");
    }
}