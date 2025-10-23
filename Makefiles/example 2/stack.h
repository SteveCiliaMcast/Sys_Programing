#include <stdbool.h>

typedef struct nodeRec
{
    int item;
    struct nodeRec *next;
} node;

typedef node *nodePtr;

nodePtr createStack(void);
nodePtr createNode(int value);
bool push(nodePtr *top, int value);
bool pop(nodePtr *top, int *value);
bool isEmptyStack(nodePtr top);
void showStack(nodePtr top);
int stackSize(nodePtr top);