/*
(Sales Commissions) Use a one-dimensional array to solve the following problem. A company pays its salespeople on a commission basis. The salespeople receive $200 per week plus 9% of
their gross sales for that week. For example, a salesperson who grosses $3,000 in sales in a week receives $200 plus 9% of $3,000, or a total of $470. Write a C program (using an array of counters)
that determines how many of the salespeople earned salaries in each of the following ranges (assume
that each salesperson’s salary is truncated to an integer amount):
*/
#include <stdio.h>
#include <stdbool.h>

void storeSalary(int salary, int salaryCategory[]);

int main(void)
{
    /*
        salary = 200 + 0.09 * grossSales
    */

    int salaryCategory[9] = {0};
    bool continueProgram = true;

    do
    {
        int salary;
        puts("Insert gross sales");
        scanf("%d", &salary);
        if (salary < 0)
        {
            continueProgram = false;
        }
        else
        {
            storeSalary(salary, salaryCategory);
        }
    } while (continueProgram);
    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", salaryCategory[i]);
    }
}
void storeSalary(int salary, int salaryCategory[])
{
    if (salary > 1000)
    {
        salaryCategory[8]++;
    }
    else
    {
        salaryCategory[0]++;
    }
}