/*
14.3 (Printing Command-Line Arguments) Write a program that prints the command-line arguments of the program.
*/
#include <stdio.h>
int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("ARGUMENT: %s\n", argv[i]);
    }
}