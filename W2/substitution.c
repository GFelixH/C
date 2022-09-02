// WIP
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int checkArguments(char **argv);
void substitutionEncriptation(const char *key);
void substitutionDecriptation(const char *key);
void usage();

int main(int argc, char *argv[])
{
    int runProgram;
    char *key;

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
    key = argv[1];

    if (runProgram == 1)
    {
        substitutionEncriptation(key);
    }
    else
    {
        substitutionDecriptation(key);
    }
    return 0;
}
void substitutionDecriptation(const char *key)
{
    int index;
    char text[100] = "", ciphertext[100] = "";
    printf("%s", "ciphertext : ");
    fflush(stdin);
    fgets(text, 100, stdin);
    for (int i = 0; i < strlen(text); i++)
    {
        short isLowerCase = 0;
        char charStream = text[1];
        if (islower(charStream))
        {
            isLowerCase = 1;
            charStream = toupper(charStream);
        }
        for (int i = 0; i < strlen(key); i++)
        {
            if (charStream == key[i])
            {
                index = i;
            }
        }
        if (isLowerCase)
        {
            ciphertext[i] = (char)(index + 1 + 96);
        }
        else
        {
            ciphertext[i] = (char)(index + 1 + 64);
        }
    }
    printf("\nplaintext : %s\n\n", ciphertext);
}
void substitutionEncriptation(const char *key)
{
    char text[100] = "", ciphertext[100] = "";
    printf("%s", "plaintext : ");
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
}
void usage()
{
    puts("USAGE\n./substitution key encript\n./caesar key decript");
}
int checkArguments(char **argv)
{
    char *firstArgument = argv[1];
    char *secondArgument = argv[2];
    if (strlen(firstArgument) != 26)
    {
        return 0;
    }
    for (int i = 0; i < strlen(firstArgument) - 1; i++)
    {
        if ((int)firstArgument[i] < 65 || (int)firstArgument[i] > 90)
        {
            return 0;
        }
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
