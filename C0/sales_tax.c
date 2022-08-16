// sales_tax.c
#include <stdio.h>
int main(void)
{
    /*
    while entrada valida
    calcular com base na entrada impostos
    while collected != -1
    total colections = %.2f collected
    sales = float vendas/1,09
    county sales = sales*0,05
    state sales = sales * 0,04
    total tax = sales*0,05+sales * 0,04
    */
    float sales, collected;
    char month[20];

    printf("%s", "Enter total amount collected (-1 to quit): ");
    scanf("%f", &collected);
    if (collected != -1)
    {
        do
        {
            printf("%s", "Enter name of month: ");
            scanf("%s", month);
            printf("Total Collections: $ %.2f\n", collected);
            sales = (float)collected / 1.09;
            printf("Sales: $ %.2f\n", sales);
            printf("County Sales Tax: $ %.2f\n", sales * 0.05);
            printf("State Sales Tax: $ %.2f\n", sales * 0.04);
            printf("Total Sales Tax Collected : $ %.2f\n\n\n\n", (sales * 0.04) + (sales * 0.05));
            printf("%s", "Enter total amount collected (-1 to quit): ");
            scanf("%f", &collected);
        } while (collected != -1);
    }
}