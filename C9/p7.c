/*
9.12 (Printing a Question Mark) Write a program that determines whether ? can be printed as
part of a printf format control string as a literal character rather than using the \? escape sequence.
*/
#include <stdio.h>
int main(void)
{
    printf("? %s", "ABCD");
    return 0;
}