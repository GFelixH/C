
#include <stdio.h> 4 5 // function main begins program execution
int main(void)
{
    char array[5] = {1, 2, 3, 4, 5}; // define an array of size 5
    printf(" array = %p\n&array[0] = %p\n &array = %p\n", array, &array[0], &array);
}
