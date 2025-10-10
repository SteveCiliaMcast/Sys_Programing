#include <stdio.h>

static void discard_remaining_input(void);

int main(void) {
    double first = 0.0;
    double second = 0.0;

    printf("Enter the first number: ");
    if (scanf("%lf", &first) != 1) {
        fprintf(stderr, "Invalid input for the first number.\n");
        discard_remaining_input();
        return 1;
    }

    printf("Enter the second number: ");
    if (scanf("%lf", &second) != 1) {
        fprintf(stderr, "Invalid input for the second number.\n");
        discard_remaining_input();
        return 1;
    }
    discard_remaining_input();

    double sum = first + second;
    double average = sum / 2.0;
    double sum_of_squares = (first * first) + (second * second);

    printf("Sum: %.2f\n", sum);
    printf("Average: %.2f\n", average);
    printf("Sum of squares: %.2f\n", sum_of_squares);

    return 0;
}

static void discard_remaining_input(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}
