#include <stdio.h>
#include <limits.h>

int main(void) {
    const int step = 10000;
    int value = 0;
    long long iterations = 0;

    printf("Incrementing `int` value by %d each step:\n", step);
    while (value <= INT_MAX - step) {
        printf("Iteration %-8lld Value: %d\n", iterations, value);
        value += step;
        ++iterations;
    }

    printf("Iteration %-8lld Value: %d\n", iterations, value);
    printf("Reached the last value before risking overflow.\n");
    printf("INT_MAX on this system: %d\n", INT_MAX);

    long long next_value = (long long)value + step;
    printf("Attempting to add %d once more would need value: %lld (using long long).\n", step, next_value);

    int overflowed = value + step;
    printf("Storing that result in an int yields: %d (overflow leads to undefined behavior).\n", overflowed);

    return 0;
}
