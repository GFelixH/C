#include <stdio.h>
#include <string.h>
int main(void)
{
    int a;
    char b[6] = "-1234";
    sscanf(b, "%d", &a);
    printf("%d", a);
}