#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkArguments(char **argv);
void caesarEncriptation(int key);
void caesarDecriptation(int key);
void usage();

int main(int argc, char *argv[])
{
    int runProgram, key;

    if (argc < 3)
    {
        usage();
        exit(EXIT_FAILURE);
    }

    runProgram = checkArguments(argv);

    if (runProgram == 0)
    {
        usage();
        exit(EXIT_FAILURE);
    }

    sscanf(argv[1], "%d", &key);

    if (runProgram == 1)
    {
        caesarEncriptation(key);
    }
    else
    {
        caesarDecriptation(key);
    }
    return 0;
}
void caesarDecriptation(int key)
{
    char text[100] = "", ciphertext[100] = "";
    printf("%s", "ciphertext: ");
    fflush(stdin);
    fgets(text, 100, stdin);
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
}
void caesarEncriptation(int key)
{
    char text[100] = "", ciphertext[100] = "";
    printf("%s", "plaintext: ");
    fflush(stdin);
    fgets(text, 100, stdin);
    for (int i = 0; i < strlen(text) - 1; i++)
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
        charvalue = (charvalue + key) % 26;
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
}
void usage()
{
    puts("USAGE\n./caesar key encript\n./caesar key decript");
}
int checkArguments(char **argv)
{
    char *firstArgument = argv[1];
    char *secondArgument = argv[2];

    for (int i = 0; i < strlen(firstArgument) - 1; i++)
    {
        if ((int)firstArgument[i] < 48 || (int)firstArgument[i] > 57)
        {
            return 0;
        }
    }
    if ((int)firstArgument[1] < 0)
    {
        return 0;
    }
    int toEncript = strcmp(secondArgument, "encript");
    if (!toEncript)
    {
        return 1;
    }
    int toDecript = strcmp(secondArgument, "decript");
    if (!toDecript)
    {
        return 2;
    }
    return 0;
}
