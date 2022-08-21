/*
7.27 (Machine-Language Programming) Let’s create a computer we’ll call the Simpletron. As its
name implies, it’s a simple machine, but as we’ll soon see, it’s a powerful one as well. The Simpletron runs programs written in the only language it directly understands—that is, Simpletron Machine Language, or SML for short.
*/
#include <stdio.h>
#define MEMORY_SIZE 100

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

int simpletron(int memory[MEMORY_SIZE], int *accPtr);
int inputInstructions(int memory[MEMORY_SIZE]);
void greetings();
void read(int m[MEMORY_SIZE], int operand);
void write(int m[MEMORY_SIZE], int operand);
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
            printf("\n%2d", i);
        }
        printf(" %+05d", m[i]);
    }
}
int simpletron(int memory[MEMORY_SIZE], int *accPtr)
{
    int accumulator = 0;
    int operation, operand, counter = 0;
    enum program
    {
        STOP,
        CONTINUE
    };
    enum program continueProgram = CONTINUE;

    for (int i = 0; i < MEMORY_SIZE && continueProgram; i++)
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
            read(memory, operand);
            break;
        case WRITE:
            write(memory, operand);
            break;
        case LOAD:
            accumulator = memory[operand];
            break;
        case STORE:
            memory[operand] = accumulator;
            break;
        case ADD:
            accumulator += memory[operand];
            break;
        case SUBTRACT:
            accumulator -= memory[operand];
            break;
        case MULTIPLY:
            accumulator *= memory[operand];
            break;
        case DIVIDE:
            accumulator = memory[operand] / accumulator;
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
        case HALT:
            continueProgram = STOP;
            break;
        default:
            break;
        }
    }
    *accPtr = accumulator;
    return counter;
}

void write(int m[MEMORY_SIZE], int operand)
{
    printf("OPERAND: %d\n", operand);
    printf("%d\n", m[operand]);
}
void read(int m[MEMORY_SIZE], int operand)
{
    int input;
    puts("Insert number");
    scanf("%d", &input);
    m[operand] = input;
}
int inputInstructions(int memory[MEMORY_SIZE])
{
    int instruction;

    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        printf("%02d  ?  ", i);
        scanf("%d", &instruction);
        memory[i] = instruction;
        if (instruction == -99999)
        {
            return i++;
        }
    }
    return 100;
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
