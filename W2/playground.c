
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
    char text[100] = "HELLO HELLO", ciphertext[100] = "";
    printf("%s", "plaintext: ");
    char key[27] = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
    // fflush(stdin);
    // fgets(text, 100, stdin);
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
        if (isUpperCase)
        {
            char c = toupper(key[charvalue - 1]);
            ciphertext[i] = c;
        }
        else
        {
            char c = tolower(key[charvalue - 1]);
            ciphertext[i] = c;
        }
    }
    printf("\nCiphertext : %s\n\n", ciphertext);
    return 0;
}