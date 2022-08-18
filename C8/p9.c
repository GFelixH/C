/*
8.14 (Tokenizing Telephone Numbers)
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char base[15] = "";
    char *strToken;
    char tokens[] = " -";
    char phoneNumber[8] = "";
    int areaCode;
    long int phone;

    puts("Insert telephone number in the format: (xxx) xxx-xxxx");
    fgets(base, 15, stdin);

    strToken = strtok(base, tokens);
    sscanf(strToken, "(%d)", &areaCode);

    strToken = strtok(NULL, tokens);
    while (strToken != NULL)
    {
        strcat(phoneNumber, strToken);
        strToken = strtok(NULL, tokens);
    }
    sscanf(phoneNumber, "%ld", &phone);
    printf("AREACODE: %d\nNUMBER: %ld\n", areaCode, phone);

    return 0;
}