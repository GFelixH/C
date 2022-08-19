/*
10.9 (Using Unions) Create union floatingPoint with members float f, double d and long
double x. Write a program that inputs values of type float, double and long double and stores the
values in union variables of type union floatingPoint. Each union variable should be printed as a
float, a double and a long double. Do the values always print correctly?
*/
#include <stdio.h>

int main(void)
{
    union floatingPoint
    {
        /* data */
        float f;
        double d;
        long double x;
    } myFloating;

    scanf("%f%lf%Lf", &myFloating.f, &myFloating.d, &myFloating.x);
    printf("%f %lf %Lf", myFloating.f, myFloating.d, myFloating.x);
    return 0;
}