#include <stdio.h>

int main(void)
{
    int h;
    puts("Insert level");
    scanf("%d", &h);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            printf("%s", " ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%s", "#");
        }
        printf("%s", " ");
        for (int j = 0; j < i; j++)
        {
            printf("%s", "#");
        }
        printf("%s", "\n");
    }
    return 0;
}