/*
9.10(Temperature Conversions)Write a program that converts integer Fahrenheit temperatures
from 0 to 212 degrees to floating- point Celsius temperatures with 3 digits of precision.Perform the calculation using the formula celsius = 5.0 / 9.0 * (fahrenheit - 32);
The output should be printed in two right-justified columns of 10 characters each, and the Celsius
temperatures should be preceded by a sign for both positive and negative values.
*/
#include <stdio.h>

int main(void)
{
    int f = 2322;
    double c = 5.0 / 9.0 * (double)(f - 32);

    printf("%-10d%-10.3lf", f, c);
    return 0;
}
