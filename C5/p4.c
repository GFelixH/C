/*
(Currency Conversion) Implement the following double functions:
a) Function toYen takes an amount in US dollars and returns the Yen equivalent.
b) Function toEuro takes an amount in US dollars and return the Euro equivalent
c) Use these functions to write a program that prints charts showing the Yen and Euro
equivalents of a range of dollar amounts. Print the outputs in a neat tabular format. Use
an exchange rate of 1 USD = 134.99  Yen and 1 USD =0.98 Euro
*/
#include <stdio.h>

double toYen(double);
double toEuro(double);

int main(void)
{
    puts("\t USD          Yen         Euro");
    for (double usd = 1; usd < 100000000; usd *= 50)
    {
        printf("%12.2f %12.2f %12.2f\n", usd, toYen(usd), toEuro(usd));
    }
    return 0;
}
double toYen(double usd)
{
    return usd * 134.99;
}
double toEuro(double usd)
{
    return usd * 0.98;
}