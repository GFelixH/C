#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *rightPtr;
    struct node *leftPtr;
};
typedef struct node node;

void printPostOrder(node *nodePtr);
void printPreOrder(node *nodePtr);
void printInOrder(node *nodePtr);
void insertNode(node **nodePtr, int value);

int main(void)
{
    node *root = NULL;
    printPostOrder(root);
    puts(" ");
    insertNode(&root, 2);
    insertNode(&root, 1);
    insertNode(&root, 0);
    insertNode(&root, -1);
    insertNode(&root, -2);
    insertNode(&root, 4);
    insertNode(&root, 5);
    insertNode(&root, 6);
    printPostOrder(root);
    puts(" ");
    printPreOrder(root);
    puts(" ");
    printInOrder(root);
    puts(" ");
    return 0;
}
void insertNode(node **nodePtr, int value)
{
    if (*nodePtr == NULL)
    {
        // new tree
        *nodePtr = malloc(sizeof(node));

        if (*nodePtr != NULL)
        {
            (*nodePtr)->value = value;
            (*nodePtr)->leftPtr = NULL;
            (*nodePtr)->rightPtr = NULL;
        }
        else
        {
            puts("NO MEMORY");
        }
    }
    else
    {
        // tree alredy existis
        if (value < (*nodePtr)->value)
        {
            insertNode(&((*nodePtr)->leftPtr), value);
        }
        else if (value > (*nodePtr)->value)
        {
            insertNode(&((*nodePtr)->rightPtr), value);
        }
        else
        {
            puts("DUPLICATE DATA");
        }
    }
}
void printInOrder(node *nodePtr)
{
    if (nodePtr != NULL)
    {
        printInOrder(nodePtr->leftPtr);
        printf("%3d", nodePtr->value);
        printInOrder(nodePtr->rightPtr);
    }
}
void printPreOrder(node *nodePtr)
{
    if (nodePtr != NULL)
    {
        printf("%3d", nodePtr->value);
        printInOrder(nodePtr->leftPtr);
        printInOrder(nodePtr->rightPtr);
    }
}
void printPostOrder(node *nodePtr)
{
    if (nodePtr != NULL)
    {
        printInOrder(nodePtr->leftPtr);
        printInOrder(nodePtr->rightPtr);
        printf("%3d", nodePtr->value);
    }
}