#include <stdbool.h>
#include <stdlib.h>

typedef struct nodeRec
{
    int item;
    struct nodeRec *next;
} node;

typedef node *nodePtr;

// Create an empty stack
nodePtr createStack(void)
{
    return NULL;
}

// Create a new node
nodePtr createNode(int value)
{
    nodePtr newNodePtr = (nodePtr)malloc(sizeof(node));
    if (newNodePtr == NULL)
    {
        return NULL; // memory allocation failed
    }
    newNodePtr->item = value;
    newNodePtr->next = NULL;
    return newNodePtr;
}

// Push an item on top
bool push(nodePtr *top, int value)
{
    nodePtr newNodePtr = createNode(value);
    if (newNodePtr == NULL)
        return false;
    newNodePtr->next = *top;
    *top = newNodePtr;
    return true;
}

// Pop an item from stack
bool pop(nodePtr *top, int *value)
{
    if (*top == NULL)
        return false;
    nodePtr tempPtr = *top;
    *value = tempPtr->item;
    *top = tempPtr->next;
    free(tempPtr);
    return true;
}

// Check if stack is empty
bool isEmptyStack(nodePtr top)
{
    return (top == NULL);
}

// Display all items
void showStack(nodePtr top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents (top -> bottom): ");
    nodePtr current = top;
    while (current != NULL)
    {
        printf("%d ", current->item);
        current = current->next;
    }
    printf("\n");
}

// Count items
int stackSize(nodePtr top)
{
    int count = 0;
    for (nodePtr current = top; current != NULL; current = current->next)
    {
        count++;
    }
    return count;
}