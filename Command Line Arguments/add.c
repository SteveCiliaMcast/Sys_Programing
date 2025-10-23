/*
Write a C program that takes two command line arguments representing integers,
adds them together, and prints the result. If the user does not provide exactly
two arguments, the program should display an error message.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check if exactly two arguments are provided - there should be 3 including program name
    if (argc != 3)
    {
        printf("Error: Please provide exactly two integer arguments.\n");
        return 1; // Return with error code
    }

    // Convert command line arguments from strings to integers
    int num1 = atoi(argv[1]); // atoi: ASCII to Integer
    int num2 = atoi(argv[2]);

    // Calculate the sum
    int sum = num1 + num2;

    // Print the result
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    return 0; // Successful execution
}