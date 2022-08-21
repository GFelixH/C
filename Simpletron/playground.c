#include <stdio.h>
#define MEMORY_SIZE 100

void inputInstructions(int memory[MEMORY_SIZE])
{
    int instruction;

    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        printf("%02d  ?  ", i);
        scanf("%d", &instruction);
        memory[i] = instruction;
        if (instruction == -99999)
        {
            break;
        }
    }
}
void printMemory(int m[MEMORY_SIZE])
{
    puts("PRINT MEMORY");
    for (size_t i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            printf("%8d", i);
        }
        else
        {
            printf("%6d", i);
        }
    }

    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n%2d", i);
        }
        printf(" %+05d", m[i]);
    }
}
int main(void)
{
    int memory[MEMORY_SIZE] = {0};
    inputInstructions(memory);
    printMemory(memory);
}