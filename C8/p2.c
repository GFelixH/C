/*
8.5 (Character Testing) Write a program that inputs a character from the keyboard and tests it
with each of the functions in the character-handling library. The program should print the value
returned by each function.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int myChar;

    myChar = getchar();
    putchar(myChar);
    printf("isblank %d\nisdigit %d\nisalnum %d\nisspace %d\niscntrl %d\nispunct %d\nisprint %d\nisgraph %d\nisblank %d\n ", isblank(myChar), isdigit(myChar), isalnum(myChar), isxdigit(myChar), islower(myChar), isupper(myChar), isspace(myChar), iscntrl(myChar),
           ispunct(myChar), isprint(myChar), isgraph(myChar), isblank(myChar));
}