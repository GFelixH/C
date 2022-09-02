#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char text[100] = "IFMMP IFMMP", ciphertext[100] = "";
    int key = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        short isUpperCase = 0;
        int charvalue = (int)text[i];
        if (charvalue == (int)' ')
        {
            ciphertext[i] = ' ';
            continue;
        }
        else if (charvalue <= 90)
        {
            charvalue -= 64;
            isUpperCase = 1;
        }
        else
        {
            charvalue -= 96;
        }
        charvalue = (charvalue - key);
        if (charvalue == 0)
        {
            charvalue = 26;
        }
        if (isUpperCase)
        {
            char c = (char)(charvalue + 64);
            ciphertext[i] = c;
        }
        else
        {
            char c = (char)(charvalue + 96);
            ciphertext[i] = c;
        }
    }

    printf("\nCiphertext : %s\n\n", ciphertext);
    return 0;
}