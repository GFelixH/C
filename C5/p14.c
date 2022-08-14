#include <stdio.h>

static int counter = 0;
int main(void)
{
    counter++;
    printf("%d", counter);
    main();
}