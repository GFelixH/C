/*
9.15 (Reading Strings in Quotes) In some programming languages, strings are entered surrounded by either single or double quotation marks. Write a program that reads the three strings suzy,
"suzy" and 'suzy'. Are the single and double quotes ignored by C or read as part of the string?
*/
#include <stdio.h>
int main(void)
{
    char s[100] = "";

    scanf("%s", &s);
    puts(s);
    scanf("%s", &s);
    puts(s);
    scanf("%s", &s);
    puts(s);

    return 0;
}