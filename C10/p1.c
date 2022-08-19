/*
10.3 Write code to accomplish each of the following:
a) Define a structure called part containing unsigned int variable partNumber and char
array partName with values that may be as long as 25 characters (including the terminating null character).
b) Define Part to be a synonym for the type struct part.
c) Use Part to declare variable a to be of type struct part, array b[10] to be of type struct
part and variable ptr to be of type pointer to struct part.
d) Read a part number and a part name from the keyboard into the individual members
of variable a.
e) Assign the member values of variable a to element 3 of array b.
f) Assign the address of array b to the pointer variable ptr.
g) Print the member values of element 3 of array b using the variable ptr and the structure
pointer operator to refer to the members.
*/
#include <stdio.h>

int main(void)
{
    typedef struct
    {
        unsigned int partNumber;
        char partName[25];
    } Part;
    Part a;
    Part b[10];
    Part *ptr;
    scanf("%d %24s", &a.partNumber, &a.partName);
    b[3] = a;
    ptr = &b[0];
    printf("%s %d", (ptr + 3)->partName, (ptr + 3)->partNumber);

    return 0;
}