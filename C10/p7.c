/*
10.12 (Packing Characters into an Integer) The left-shift operator can be used to pack four character values into a four-byte unsigned int variable. Write a program that inputs four characters from
the keyboard and passes them to function packCharacters. To pack four characters into an unsigned int variable, assign the first character to the unsigned int variable, shift the unsigned int
variable left by 8 bit positions and combine the unsigned variable with the second character using
the bitwise inclusive OR operator. Repeat this process for the third and fourth characters. The program should output the characters in their bit format before and after they’re packed into the unsigned int to prove that the characters are in fact packed correctly in the unsigned int variable.
*/
#include <stdio.h>
int main(void)
{

    char a = 'a';
    char b = 'b';
    char c = 'c';
    char d = 'd';
    printf("%c %c %c %c", a, b, c, d);
    unsigned int compact = a;
    compact <<= 8;
    compact = compact | b;
    compact <<= 8;
    compact = compact | c;
    compact <<= 8;
    compact = compact | d;
    printf("%u", compact);
    return 0;
}