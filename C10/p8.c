/*
ERROR
10.13 (Unpacking Characters from an Integer) Using the right-shift operator, the bitwise AND
operator and a mask, write function unpackCharacters that takes the unsigned int from
Exercise 10.12 and unpacks it into four characters. To unpack characters from a four-byte unsigned
int, combine the unsigned int with the mask 4278190080 (11111111 00000000 00000000 00000000)
and right shift the result 8 bits. Assign the resulting value to a char variable. Then combine the unsigned int with the mask 16711680 (00000000 11111111 00000000 00000000). Assign the result to
another char variable. Continue this process with the masks 65280 and 255. The program should
print the unsigned int in bits before it’s unpacked, then print the characters in bits to confirm that
they were unpacked correctly.
*/
#include <stdio.h>
int main(void)
{
    unsigned int base, temp;
    base = 1633837924;
    char a, b, c, d;
    unsigned int mask;
    mask = 4278190080;
    base = base & mask;
    base >>= 8;
    a = base;

    mask = 16711680;
    base = base & mask;
    base >>= 8;
    b = base;

    mask = 65280;
    base = base & mask;
    base >>= 8;
    c = base;

    mask = 255;
    base = base & mask;
    base >>= 8;
    d = base;

    printf("%c %c %c %c", a, b, c, d);
    return 0;
}