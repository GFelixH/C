#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *nextPtr;
};
typedef struct node node;

void enqueue(node **head, node **tail, int value);
void printQueue(node *stream);
void dequeue(node **head, node **tail);

int main(void)
{
    node *headPtr = NULL;
    node *tailPtr = NULL;

    printQueue(headPtr);
    enqueue(&headPtr, &tailPtr, 1);
    printQueue(headPtr);
    dequeue(&headPtr, &tailPtr);
    printQueue(headPtr);
    enqueue(&headPtr, &tailPtr, 2);
    printQueue(headPtr);
    printQueue(headPtr);
    enqueue(&headPtr, &tailPtr, 3);
    printQueue(headPtr);
    enqueue(&headPtr, &tailPtr, 4);
    printQueue(headPtr);
    enqueue(&headPtr, &tailPtr, 5);
    printQueue(headPtr);
    dequeue(&headPtr, &tailPtr);
    printQueue(headPtr);
    dequeue(&headPtr, &tailPtr);
    printQueue(headPtr);
    dequeue(&headPtr, &tailPtr);
    printQueue(headPtr);
    dequeue(&headPtr, &tailPtr);
    printQueue(headPtr);

    return 0;
}
void printQueue(node *stream)
{
    if (stream == NULL)
    {
        puts("IS EMPTY");
    }
    else
    {
        puts("THE QUEUE IS");
        while (stream != NULL)
        {
            printf("%d --> ", stream->value);
            stream = stream->nextPtr;
        }
        puts("NULL");
    }
}
void dequeue(node **head, node **tail)
{
    node *temp = malloc(sizeof(node));
    if (temp != NULL)
    {
        int value = (*head)->value;
        temp = *head;
        *head = (*head)->nextPtr;

        if (*head == NULL)
        {
            *tail = NULL;
        }
        free(temp);
    }
    else
    {
        puts("NO MEORY");
    }
}
void enqueue(node **head, node **tail, int value)
{
    node *newPtr = malloc(sizeof(node));
    if (newPtr != NULL)
    {
        newPtr->value = value;
        newPtr->nextPtr = NULL;
        if (*head == NULL)
        {
            // empty new is head
            *head = newPtr;
            // tail is null
        }
        else
        {
            // adds to the tail
            (*tail)->nextPtr = newPtr;
        }
        // new tail ptr
        *tail = newPtr;
    }
    else
    {
        puts("NO MEMORY");
    }
}