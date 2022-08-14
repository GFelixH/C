/*
(Knight’s Tour)
Euler:  Can the chess piece called the knight move around an empty chessboard and touch each of the 64 squares once and only once?
*/
// : heuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GAMES 2
#define BOARD_SIZE 8

void printBoard(const int board[BOARD_SIZE][BOARD_SIZE], int x, int y);
int gestMovement(const int board[BOARD_SIZE][BOARD_SIZE], int x, int y);
bool isValidMovement(int nextXPosition, int nextYPosition, const int board[BOARD_SIZE][BOARD_SIZE]);
void reinitializeBoard(int board[BOARD_SIZE][BOARD_SIZE]);

static int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
static int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main(void)
{
    // Seed the randomizer
    srand(time(NULL));

    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    board[3][4] = 1;
    int currentRow = 3, currentColumn = 4, moveNumber, movementsCounter = 0;
    int moves[64] = {0};

    // printBoard(board, currentRow, currentColumn);

    for (int i = 0; i < GAMES; i++)
    {
        reinitializeBoard(board);
        board[3][4] = 1;
        // Movement Simulator
        for (movementsCounter; movementsCounter < 64; movementsCounter++)
        {
            // Gets Movement Number
            moveNumber = gestMovement(board, currentRow, currentColumn);
            // Validates Knight's move
            if (moveNumber == -1)
            {
                break;
            }
            else
            {
                // Moves the knight
                currentRow += vertical[moveNumber];
                currentColumn += horizontal[moveNumber];
                board[currentRow][currentColumn] = 1;
            }
        } // gameSimualtor
    }     // Simulation of x Games
} // end of main
void reinitializeBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
}
bool isValidMovement(int nextXPosition, int nextYPosition, const int board[BOARD_SIZE][BOARD_SIZE])
{
    bool isInsideBoard = nextXPosition >= 0 && nextXPosition <= 7 && nextYPosition <= 7 && nextYPosition >= 0;
    bool alreadyVisited = board[nextXPosition][nextYPosition] == 1;
    return isInsideBoard && !alreadyVisited;
} // end of isValidMovement
int gestMovement(const int board[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
    int possibleMovements[7] = {
        -1, // 0
        -1, // 1
        -1, // 2
        -1, // 3
        -1, // 4
        -1, // 5
        -1  // 6
    };
    int possibleMoves = 0;
    int counter = 0;
    for (int i = 0; i <= 6; i++)
    {
        int nextXPosition = x + vertical[i];
        int nextYPosition = y + horizontal[i];
        bool currentTestMovement = isValidMovement(nextXPosition, nextYPosition, board);
        if (currentTestMovement)
        {
            possibleMovements[counter] = i;
            possibleMoves++;
            counter++;
        }
    }
    if (possibleMoves == 0)
    {
        return -1;
    }
    else
    {
        int choosenOne = rand() % possibleMoves;
        return possibleMovements[choosenOne];
    }
} // end of getsMovement
void printBoard(const int board[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
    puts("\nThe Board\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (i != x || j != y)
            {
                printf(" %d ", board[i][j]);
            }
            else
            {
                printf(" %s ", "k");
            }
        }
        puts(" ");
    }
    puts(" ");
    puts(" ");
} // end of printsBoard