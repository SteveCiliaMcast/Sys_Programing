#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <weight_kg> <height_m>\n", argv[0]);
        return 1;
    }

    double weight = atof(argv[1]);
    double height = atof(argv[2]);

    if (weight <= 0 || height <= 0)
    {
        printf("Error: Weight and height must be positive numbers.\n");
        return 1;
    }

    double bmi = weight / (height * height);
    printf("BMI: %.2f\n", bmi);

    if (bmi < 18.5)
        printf("Category: Underweight\n");
    else if (bmi < 25.0)
        printf("Category: Normal\n");
    else if (bmi < 30.0)
        printf("Category: Overweight\n");
    else
        printf("Category: Obese\n");

    return 0;
}
