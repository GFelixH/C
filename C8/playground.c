#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "(123)";
    int areaCode;

    sscanf(str1, "(%d)", &areaCode);
    printf("%d\n", areaCode);
    return 0;
}
