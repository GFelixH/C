/*
9.17 (Using %g with Various Precisions) Write a program that uses the conversion specifier g to
output the value 9876.12345. Print the value with precisions ranging from 1 to 9.
*/
#include <stdio.h>
int main(void)
{
    double d = 9876.12345;
    printf("%.1g\n", d);
    printf("%.2g\n", d);
    printf("%.3g\n", d);
    printf("%.4g\n", d);
    printf("%.5g\n", d);
    printf("%.6g\n", d);
    printf("%.7g\n", d);
    printf("%.8g\n", d);
    printf("%.9g\n", d);
    return 0;
}