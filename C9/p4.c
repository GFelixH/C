/*
9.9 (Rounding Floating-Point Numbers) Write a program that prints the value 100.453627
rounded to the nearest digit, tenth, hundredth, thousandth and ten-thousandth.
*/
#include <stdio.h>

int main(void)
{
    double b = 100.453627;

    printf("%.0lf\n", b);
    printf("%.1lf\n", b);
    printf("%.2lf\n", b);
    printf("%.3lf\n", b);
    printf("%.6lf\n", b);

    return 0;
}