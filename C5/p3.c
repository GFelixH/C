// Tempo em segundos
#include <stdio.h>

void timeInSeconds(int h, int m, int s);

int main(void)
{

    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    timeInSeconds(h, m, s);
    return 0;
}
void timeInSeconds(int h, int m, int s)
{
    if (h == 0 || h == 12 || h == 24)
    {
        printf("H:%d Min:%d Seg:%d\n", 0, m, s);
        printf("Seg:%d", s + m * 60);
    }
    else if (h < 12)
    {
        printf("H:%d Min:%d Seg:%d\n", h, m, s);
        printf("Seg:%d", s + m * 60 + h * 3600);
    }
    else
    {
        printf("H:%d Min:%d Seg:%d\n", h - 12, m, s);
        printf("Seg:%d", s + m * 60 + (h - 12) * 3600);
    }
}
