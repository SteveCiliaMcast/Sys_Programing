#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodeRec
{
    int item;
    struct nodeRec* next;
} node;

typedef node* nodePtr;


//**** function definitions
nodePtr createStack() {
    return NULL;
}

bool createNode(int n, nodePtr *p) {

    *p = (nodePtr)malloc(sizeof(node));
    if (*p == NULL) {
        return false;
    }
    else {
        (*p)->item = n;   // this means (*p).item
        (*p)->next = NULL;  // this means (*p).next
        return true;
    }
}

void showNode(nodePtr p) {
    if (p != NULL) {
        printf("Item %d ", p->item);
    }else {
        printf("NULL data");
    }
}

int main() {
    nodePtr top;
    top = createStack();
    nodePtr p;
    bool success = createNode(5, &p); // we need to set p as an OUTPUT parameter otherwise its data will be lost
    showNode(p);
}