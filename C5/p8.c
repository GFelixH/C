/*
(Quality Points for Student’s Grades) Write a function toQualityPoints that inputs a student’s average and returns 4 it’s 90–100, 3 if it’s 80–89, 2 if it’s 70–79, 1 if it’s 60–69, and 0 if the
average is lower than 60
*/
#include <stdio.h>

int toQualityPoints(int x);

int main(void)
{
    int average, qualityPoints;

    puts("Insert average: ");
    scanf("%d", &average);

    qualityPoints = toQualityPoints(average);

    printf("Category: %d\n", qualityPoints);
}
int toQualityPoints(int x)
{
    if (x >= 90)
    {
        return 4;
    }
    else if (x >= 80)
    {
        return 3;
    }
    else if (x >= 70)
    {
        return 2;
    }
    else if (x >= 60)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}