#include <stdio.h>
#include <math.h>

int main(void)
{

    float a = 1.256;
    float b = floor(a * 100 + .5) / 100;
    printf("%f", b);

    system("pause");
    return 0;
}