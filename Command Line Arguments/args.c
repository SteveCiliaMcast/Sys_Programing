#include <stdio.h>

/*
This program accepts command line arguments.

argc is an integer and it stores the NUMBER OF ARGUMENTS passed to the program
    - remember that the name of the program itself counts as an argument

argv is an array of dynamic strings (character pointers)
    - it stores the name of the program and the rest of the arguments
*/

// Simple program that accepts command line arguments and displays them
int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
}