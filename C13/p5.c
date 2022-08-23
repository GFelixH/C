/*
13.8 (Printing a String) Write a program that defines and uses macro PRINT to print a string value
*/
#include <stdio.h>
#define PRINT(x) (printf("%s\n", x))
int main(void)
{
    char string[] = "ABCD";
    PRINT(string);
    return 0;
}