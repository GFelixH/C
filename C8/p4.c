/*
8.7 (Converting Strings to Integers for Calculations) Write a program that inputs six strings
that represent integers, converts the strings to integers, and calculates the sum and average of the
six values.
8.8 (Converting Strings to Floating Point for Calculations) Write a program that inputs six
strings that represent floating-point values, converts the strings to double values, stores the values
into a double array and calculates the sum, and average of the values
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    int a, b, c, d, e, f;
    fgets(s, 99, stdin);
    sscanf(s, "%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d %d %d %d %d %d", a, b, c, d, e, f);

    puts(" ");
    char s2[100];
    double a2, b2, c2, d2, e2, f2;
    fgets(s2, 99, stdin);
    sscanf(s2, "%lf%lf%lf%lf%lf%lf", &a2, &b2, &c2, &d2, &e2, &f2);
    printf("%lf%lf%lf%lf%lf%lf", a2, b2, c2, d2, e2, f2);

    return 0;
}