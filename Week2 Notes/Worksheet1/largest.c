#include <stdio.h>

static void discard_remaining_input(void);

int main(void) {
    int numbers[10];
    int largest = 0;

    for (int i = 0; i < 10; ++i) {
        printf("Enter number %d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Invalid input encountered.\n");
            discard_remaining_input();
            return 1;
        }
        if (i == 0 || numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    discard_remaining_input();

    printf("The largest number entered was: %d\n", largest);

    return 0;
}

static void discard_remaining_input(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}
