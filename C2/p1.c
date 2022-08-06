#include <stdio.h>

int main(void)
{

    // 8vezes 8 *, tem ntem
    for (int i = 1; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            printf("%s", " * * * * * * * *\n");
        }
        else
        {
            printf("%s", "* * * * * * * * \n");
        }
    }
    return 0;
}