#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

int main()
{
    nodePtr top = createStack();
    int choice, value, popped;

    do
    {
        printf("\n     My Stack Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show Stack\n");
        printf("4. How many items on stack?\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            if (push(&top, value))
                printf("Pushed %d onto stack.\n", value);
            else
                printf("Error: Could not push value.\n");
            break;

        case 2:
            if (pop(&top, &popped))
                printf("Popped value: %d\n", popped);
            else
                printf("Stack is empty.\n");
            break;

        case 3:
            showStack(top);
            break;

        case 4:
            printf("Stack has %d item(s).\n", stackSize(top));
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}