#include <stdio.h>
int main(void)
{
    FILE *fPtr;
    int a = 42;
    int b;

    fPtr = fopen("playground.dat", "wb+");

    if (fPtr == NULL)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            puts("Writes 42");
            fwrite(&a, sizeof(int), 1, fPtr);
        }

        rewind(fPtr);

        fread(&b, sizeof(int), 1, fPtr);
        while (!feof(fPtr))
        {

            printf("%d ", b);
            fread(&b, sizeof(int), 1, fPtr);
        }
        fclose(fPtr);
    }
    return 0;
}