#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    double num1 = atof(argv[1]);
    double num2 = atof(argv[2]);

    if (num1 < num2)
        printf("Smaller number: %.2f\n", num1);
    else if (num2 < num1)
        printf("Smaller number: %.2f\n", num2);
    else
        printf("Both numbers are equal: %.2f\n", num1);

    return 0;
}
