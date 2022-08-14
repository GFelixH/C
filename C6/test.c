#include <stdio.h>
#define BOARD_SIZE 8

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]);

int main(void)
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    printBoard(board);
}
void printBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d", board[i][j]);
        }
        puts(" ");
    }
}