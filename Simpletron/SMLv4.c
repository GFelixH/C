/*
7.27 (Machine-Language Programming) Let’s create a computer we’ll call the Simpletron. As its
name implies, it’s a simple machine, but as we’ll soon see, it’s a powerful one as well. The Simpletron runs programs written in the only language it directly understands—that is, Simpletron Machine Language, or SML for short.
*/
#include <stdio.h>
#include <string.h>

#define MEMORY_SIZE 1000

#define READ 10
#define WRITE 11
#define SPACE 12
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define REMAINDER 34
#define EXPONENTIAL 35
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

int simpletron(int memory[MEMORY_SIZE], int *accPtr);
int inputInstructions(int memory[MEMORY_SIZE]);
void greetings();
void read(int m[MEMORY_SIZE], int operand);
void write(int a);
void space();
void printMemory(const int m[MEMORY_SIZE], const int accumulator, const int regCtr, const int instructions);
void gb();

int main(void)
{
    int memory[MEMORY_SIZE] = {0}, accumulator = 0;

    greetings();
    int instructions = inputInstructions(memory);
    int regCounter = simpletron(memory, &accumulator);
    printMemory(memory, accumulator, regCounter, instructions);
    gb();
}
void gb()
{
    printf("\n\n%s", "PROGRAM COMPLETED !\n\tHALTING THE MACHINE !\n\tBYE BYE    XD\n\n");
}
void printMemory(const int m[MEMORY_SIZE], const int accumulator, const int regCtr, const int instructions)
{
    printf("REGISTERS\naccumulator%+18d\ninstructionCounter%+11d\ninstructionRegister%+10d\noperation code%+15d\noperand%+22d\n\n", accumulator, instructions, m[regCtr], m[regCtr] / 100, m[regCtr] % 100);
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
            printf("\n%4d", i);
        }
        printf(" %+05d", m[i]);
    }
}
int simpletron(int memory[MEMORY_SIZE], int *accPtr)
{
    int accumulator = 0;
    int operation, operand, temp, input, counter = 0;
    enum program
    {
        STOP,
        CONTINUE
    };
    enum program machineStatus = CONTINUE;
    for (int i = 0; i < MEMORY_SIZE && machineStatus; i++)
    {
        if (memory[i] == -99999)
        {
            break;
        }
        counter++;
        operation = memory[i] / 100;
        operand = memory[i] % 100;
        switch (operation)
        {
        case READ:
            puts("Insert number");
            scanf("%d", &input);
            if (input < -9999 || input > 9999)
            {
                puts("ERROR : OUT OF RANGE");
                machineStatus = STOP;
            }
            memory[operand] = input;
            break;
        case WRITE:
            printf("%d", memory[operand]);
            write(memory[operand]);
            break;
        case SPACE:
            puts(" ");
            space();
            break;
        case LOAD:
            accumulator = memory[operand];
            break;
        case STORE:
            memory[operand] = accumulator;
            break;
        case ADD:
            accumulator += memory[operand];
            temp = accumulator;
            if (temp < -9999 || temp > 9999)
            {
                puts("ERROR : ARITHMETIC OVERFLOW");
                machineStatus = STOP;
            }
            break;
        case SUBTRACT:
            accumulator -= memory[operand];
            temp = accumulator;
            if (temp < -9999 || temp > 9999)
            {
                puts("ERROR : ARITHMETIC OVERFLOW");
                machineStatus = STOP;
            }
            break;
        case MULTIPLY:
            accumulator *= memory[operand];
            temp = accumulator;
            if (temp < -9999 || temp > 9999)
            {
                puts("ERROR : ARITHMETIC OVERFLOW");
                machineStatus = STOP;
            }
            break;
        case DIVIDE:
            if (accumulator == 0)
            {
                puts("ERROR : DIVISION BY ZERO");
                machineStatus = STOP;
            }
            accumulator = memory[operand] / accumulator;
            temp = accumulator;
            if (temp < -9999 || temp > 9999)
            {
                puts("ERROR : ARITHMETIC OVERFLOW");
                machineStatus = STOP;
            }
            break;
        case BRANCH:
            i = operand;
            break;
        case BRANCHNEG:
            if (accumulator < 0)
            {
                i = operand;
            }
            break;
        case BRANCHZERO:
            if (accumulator == 0)
            {
                i = operand;
            }
            break;
        case REMAINDER:
            if (accumulator == 0)
            {
                puts("ERROR : DIVISION BY ZERO");
            }
            accumulator = memory[operand] % accumulator;
            break;
        case EXPONENTIAL:
            for (int i = 1; i <= memory[operand]; i++)
            {
                accumulator *= memory[operand];
            }
            break;
        case HALT:
            machineStatus = STOP;
            break;
        default:
            break;
        }
    }
    *accPtr = accumulator;
    return counter;
}
void write(int a)
{
    FILE *F = fopen("output.txt", "w");
    char myInt[6] = "";
    sprintf(myInt, "%d", a);
    fputs(myInt, F);
    fclose(F);
}
void space()
{
    FILE *F = fopen("output.txt", "w");
    fputc('\n', F);
    fclose(F);
}
int inputInstructions(int memory[MEMORY_SIZE])
{
    int instruction = 0;
    FILE *F;
    char path[32] = "";
    puts("Enter the path of the file with machine language :");
    fgets(path, 32, stdin);
    path[strlen(path) - 1] = '\0';
    F = fopen(path, "r");
    if (F == NULL)
    {
        puts("ERROR : CANNOT READ FILE");
        return 0;
    }
    else
    {
        int command;
        for (size_t i = 0; i < MEMORY_SIZE && command != -99999; i++)
        {
            char row[7] = "";
            fgets(row, 7, F);
            sscanf(row, "%d", &command);
            memory[i] = command;
            instruction++;
        }
    }
    fclose(F);
    return instruction;
}
void greetings()
{
    puts("*** Welcome to Simpletron! ***");
    puts("*** Please enter your program one instruction ***");
    puts("*** (or data word) at a time. I will type the ***");
    puts("*** location number and a question mark (?). ***");
    puts("*** You then type the word for that location. ***");
    puts("*** Type the sentinel -99999 to stop entering ***");
    puts("*** your program. ***");
}
