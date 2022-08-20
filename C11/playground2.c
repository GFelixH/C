#include <stdio.h>
int main(void)
{
    FILE *fPtr;
    fPtr = fopen("playground2.dat", "wb+");
    int number = 42;
    fwrite(&number, sizeof(int), 1, fPtr);
    rewind(fPtr);
    int a;
    fread(&a, sizeof(int), 1, fPtr);
    printf("%d\n", a);
    fclose(fPtr);

    return 0;
}