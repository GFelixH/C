#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *nextNode;
};
typedef struct node node;

void insert(node **start, int value);
void delete (node **start, int value);
void printLinkedList(node *streamPtr);

int main(void)
{
    node *start = NULL;

    printLinkedList(start);
    insert(&start, 2);
    printLinkedList(start);
    insert(&start, 1);
    printLinkedList(start);
    insert(&start, 3);
    printLinkedList(start);
    delete (&start, 0);
    printLinkedList(start);
    delete (&start, 2);
    printLinkedList(start);
    delete (&start, 1);
    printLinkedList(start);
    delete (&start, 3);
    printLinkedList(start);
    return 0;
}
void printLinkedList(node *streamPtr)
{
    if (streamPtr != NULL)
    {
        puts("THE LIST IS");
        while (streamPtr != NULL)
        {
            printf("%d --> ", streamPtr->number);
            streamPtr = streamPtr->nextNode;
        }
        puts("NULL");
    }
    else
    {
        puts("LIST IS EMPTY");
    }
}
void delete (node **start, int value)
{
    node *tempPtr = malloc(sizeof(node));
    if (tempPtr != NULL)
    {

        if ((*start)->number == value)
        {
            node *tempPtr = malloc(sizeof(node));
            *start = (*start)->nextNode;
            free(tempPtr);
            puts("DELETED");
        }
        else
        {

            node *previousPtr = *start;
            node *currentPtr = (*start)->nextNode;

            while (currentPtr != NULL && value != currentPtr->number)
            {
                previousPtr = currentPtr;
                currentPtr = currentPtr->nextNode; // walk through
            }

            if (currentPtr != NULL)
            {
                // does not works for the first node
                tempPtr = currentPtr;
                previousPtr->nextNode = currentPtr->nextNode;
                free(tempPtr);
                puts("DELETED");
            }
            else
            {
                puts("NOT DELETED");
            }
        }
    }
    else
    {
        puts("NO MEMORY\n");
    }
}
void insert(node **start, int value)
{
    node *newNodePtr = malloc(sizeof(node));

    if (newNodePtr != NULL)
    {
        newNodePtr->number = value;
        newNodePtr->nextNode = NULL;

        node *currentNodePtr = *start; // search current as first
        node *previusNodePtr = NULL;   // search previus is NULL

        while (currentNodePtr != NULL && value > currentNodePtr->number)
        {
            // walk through the linked list
            // > sets the order : increasing order
            previusNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->nextNode;
        }

        if (previusNodePtr == NULL)
        { // first node or before first node
            newNodePtr->nextNode = *start;
            *start = newNodePtr;
        }
        else
        {
            // not in the first node, could be the last
            previusNodePtr->nextNode = newNodePtr;
            newNodePtr->nextNode = currentNodePtr;
        }
    }
    else
    {
        puts("Memory not available.\n");
    }
}