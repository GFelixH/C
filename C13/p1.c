/*
13.4 (Volume of a Sphere) Write a program that defines a macro with one argument to compute
the volume of a sphere. The program should compute the volume for spheres of radius 1 to 10 and
print the results in tabular format. The formula for the volume of a sphere is
(4.0 / 3) * π * r3
where π is 3.14159.
*/
#include <stdio.h>
#define PI 3.14159
#define SPHERE_VOLUME(x) ((4.0 / 3) * (PI) * (x * x * x))
int main(void)
{

    printf("%lf ", SPHERE_VOLUME(1));
    printf("%lf ", SPHERE_VOLUME(2));
    printf("%lf ", SPHERE_VOLUME(3));
    printf("%lf ", SPHERE_VOLUME(4));
    printf("%lf ", SPHERE_VOLUME(5));

    return 0;
}