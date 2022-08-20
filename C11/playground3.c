#include <stdio.h>
int main(void)
{
    FILE *fPtr;
    fPtr = fopen("playground3.dat", "w+");
    int write = 42;
    int recive, response;

    if (fPtr == NULL)
    {
        return 1;
    }
    else
    {

        response = fwrite(&write, sizeof(int), 1, fPtr);
        printf("%d\n", response);

        rewind(fPtr);

        response = fread(&recive, sizeof(int), 1, fPtr);
        printf("%d\n", response);
        printf("Recive : %d\n", recive);

        fclose(fPtr);
    }
    return 0;
}