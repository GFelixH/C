// Checks if a card is value based on the Luhn’s Algorithm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 17

void programEnd();
int checksum();
int stopInput(int input);
int inputIsNumber(int input);
int equivalentInteger(int input);
void creditCardChecker();

int main(void)
{
    // EXIT MESSAGE
    atexit(programEnd);
    // Program itself
    creditCardChecker();
    return 0;
}
void creditCardChecker()
{
    while (1)
    {
        int numberCounter = 0, cardNumber[16] = {0}, isValidInput = 1, input, isValidCard;
        // Clears stdin
        fflush(stdin);
        // Prompts the user to insert numbers
        puts("Insert number of card or EOF to end the program");
        // Gets input ascii code
        input = getchar();
        while (!stopInput(input) && numberCounter < MAX_SIZE)
        {
            // if (!stopinput(input) && !inputIsNumber(input))
            if (!inputIsNumber(input))
            {
                puts("INVALID INPUT");
                isValidInput = 0;
                break;
            }
            // Stores valid number
            cardNumber[numberCounter] = equivalentInteger(input);
            numberCounter++;
            // New value
            input = getchar();
        }
        if (isValidInput)
        {
            if (input == EOF)
            {
                // EOF detected
                exit(EXIT_SUCCESS);
            }
            else
            {
                // enter line detected
                if (numberCounter < 13 || numberCounter > 16)
                {
                    puts("INVALID CARD : INCORRET NUMBER SIZE");
                }
                else
                {
                    // is a valid number size
                    isValidCard = checksum(numberCounter, cardNumber);
                    if (isValidCard)
                    {
                        // valid checksum
                        if (cardNumber[0] == 4)
                        {
                            puts("VISA CARD");
                        }
                        else
                        {
                            int firstTwoDigits = cardNumber[1] * 10 + cardNumber[0];
                            switch (firstTwoDigits)
                            {
                            case 51:
                            case 52:
                            case 53:
                            case 54:
                                puts("MASTER CARD");
                                break;
                            case 34:
                            case 37:
                                puts("American Express");
                            default:
                                puts("ERROR CREDIT CARD FLAG");
                                break;
                            }
                        }
                    }
                    else
                    {
                        puts("INVALID CARD : INCORRECT CHECKSUM");
                    }
                }
            }
        }
    }
}
int checksum(const int numberCounter, const int *array)
{
    int sum = 0;
    for (int i = numberCounter - 2; i >= 0; i = i - 2)
    {
        int stream = array[i] * 2;
        if (stream >= 10)
        {
            sum += stream / 10 + stream % 10;
        }
        else
        {
            sum += stream;
        }
    }
    for (int i = numberCounter - 1; i >= 0; i = i - 2)
    {
        sum += array[i];
    }

    return sum % 10 == 0;
}
int equivalentInteger(int input)
{
    return input - 48;
}
int inputIsNumber(int input)
{
    return input >= 48 && input <= 57;
}
int stopInput(int input)
{
    return input == 10 || input == EOF;
}
void programEnd()
{
    puts("\n\nPROGRAM ENDED");
}