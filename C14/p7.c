/*
14.8 (goto Statement) Write a program that uses goto statements and only the following three
printf statements to simulate a nested looping structure that prints a square of asterisks as shown
below:
printf("%s", "*");
printf("%s", " ");
printf("%s", "\n");
                            NOT COMPLETED
*/
#include <stdio.h>
int main(void)
{
starFirstRow:
    goto star;
newLine:
    printf("%s", "\n");
star:
    printf("%s", "*");
    goto star;
space:
    printf("%s", " ");

firstRow:
    goto starFirstRow;
firstRowEnd:
    return 0;
}