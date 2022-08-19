/*
10.5 Provide the definition for each of the following structures and unions:
a) Structure inventory containing character array partName[30], integer partNumber,
floating-point price, integer stock and integer reorder.
b) Union data containing char c, short s, long b, float f and double d.
c) A structure called address that contains character arrays
streetAddress[25], city[20], state[3] and zipCode[6].
d) Structure student that contains arrays firstName[15] and
lastName[15] and variable homeAddress of type struct address from part (c).
e) Structure test containing 16 bit fields with widths of 1 bit. The names of the bit fields
are the letters a to p.
*/
#include <stdio.h>
int main(void)
{
    typedef struct
    {
        unsigned int a : 1;
    } test;

    typedef struct
    {
        char streetAddress[25];
        char city[20];
        char state[3];
        char zipCode[6];
    } address;
    typedef struct
    {
        /* data */
        char firstName[25];
        char lastName[25];
        address homeAddress;
    } student;

    typedef struct
    {
        char partName[30];
        int partNumber;
        double prince;
        int stcok;
        int reorder;
    } inventory;

    typedef union
    {
        char c;
        short int s;
        long int b;
        float f;
        double d;
    } data;

    return 0;
}