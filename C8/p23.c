/*
8.27 (Write Your String-Conversion Functions) Write your own versions of the functions in
Fig. 8.5 for converting strings to numbers.

double strtod(const char *nPtr, char **endPtr);
Converts the string nPtr to double.

long strtol(const char *nPtr, char **endPtr, int base);
Converts the string nPtr to long.

unsigned long strtoul(const char *nPtr, char **endPtr, int base);
Converts the string nPtr to unsigned long.
*/
#include <stdio.h>
double strtod(const char *string)
{
    int result = 0;
    int counter = 0;
    while (string[counter] != '\0')
    {
        printf("%c ", string[counter]);
        int value = (int)string[counter];
        printf("%d \n", value);
        result = result * 10 + (value - 48);
        counter++;
    }
    return result;
}
int main(void)
{
    char array[] = "123";
    double teste = strtod(array);
    printf("%lf", teste);
    return 0;
}