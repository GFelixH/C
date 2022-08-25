/*
8.25 (Printing Letters for Various ASCII Codes) Write a program that inputs an ASCII code and
prints the corresponding character.
*/
#include <stdio.h>
#include <string.h>
// #define DEBUG 1
int main(void)
{
    // DIGIT DIGIT
    char myCode[100] = "";
    char *streamPtr = &myCode[0];
    char stringCode[2] = "";
    int code;

    fgets(myCode, 100, stdin);
    strncpy(stringCode, streamPtr, 2);
    sscanf(stringCode, "%2d", &code);

#ifdef DEBUG
    printf("%d\n", code);
#endif

    putchar(code);
    streamPtr += 2;

    while (code != 3)
    {
        strncpy(stringCode, streamPtr, 2);
        sscanf(stringCode, "%2d", &code);

#ifdef DEBUG
        printf("%d\n", code);
#endif

        putchar(code);
        streamPtr += 2;
    }
    puts(" ");
    return 0;
}