/*
(Maze Traversal)
There’s a simple algorithm for walking through a maze that guarantees finding the exit
(assuming there’s an exit). If there’s not an exit, you’ll arrive at the starting location again. Place
your right hand on the wall to your right and begin walking forward. Never remove your hand
from the wall. If the maze turns to the right, you follow the wall to the right. As long as you do not
remove your hand from the wall, eventually you’ll arrive at the exit of the maze. There may be a
shorter path than the one you have taken, but you’re guaranteed to get out of the maze.
Write recursive function mazeTraverse to walk through the maze. The function should
receive as arguments a 12-by-12 character array representing the maze and the starting location of
the maze. As mazeTraverse attempts to locate the exit from the maze, it should place the character
X in each square in the path. The function should display the maze after each move so the user can
watch as the maze is solved
*/
#include <stdio.h>
#include <stdbool.h>
#define MAZE_SIZE 12

void printMaze(const char maze[MAZE_SIZE][MAZE_SIZE], const int x, const int y);
int rightHasWall(const char maze[MAZE_SIZE][MAZE_SIZE], const int x, const int y, const char orientation);
int frontHasPath(const char maze[MAZE_SIZE][MAZE_SIZE], const int x, const int y, const char orientation);
char turnToRight(const char orientation);
char turnToLeft(const char orientation);
void movement(char maze[MAZE_SIZE][MAZE_SIZE], int *const xPtr, int *const yPtr, const char orientation);
int checkPosition(const int x, const int y, const int xs, const int ys);
int mazeTraverse(char maze[MAZE_SIZE][MAZE_SIZE], const int xs, const int ys, int x, int y, char orientation);

int main(void)
{
    char maze[MAZE_SIZE][MAZE_SIZE] = {
        {"############"},
        {"#...#......#"},
        {"..#.#.####.#"},
        {"###.#....#.#"},
        {"#....###.#.."},
        {"####.#.#.#.#"},
        {"#..#.#.#.#.#"},
        {"##.#.#.#.#.#"},
        {"#........#.#"},
        {"######.###.#"},
        {"#......#...#"},
        {"############"}};
    int xStart = 2;
    int position;
    int yStart = 0;
    char initialOrientation = 'R';
    int checker;

    checker = mazeTraverse(maze, xStart, yStart, xStart, yStart, initialOrientation);
    printf("\n\n%d", checker);

    return 0;
}
/*
 *Recursive function mazeTraverse to walk through the maze. The function should
 *receive as arguments a 12-by-12 character array representing the maze and the starting location of
 *the maze. As mazeTraverse attempts to locate the exit from the maze, it should place the character
 *X in each square in the path. The function should display the maze after each move so the user can
 *watch as the maze is solved
 */
int mazeTraverse(char maze[MAZE_SIZE][MAZE_SIZE], const int xs, const int ys, int x, int y, char orientation)
{
    /*
    If there’s not an exit, you’ll arrive at the starting location again. Place
    your right hand on the wall to your right and begin walking forward. Never remove your hand
    from the wall. If the maze turns to the right, you follow the wall to the right. As long as you do not
    remove your hand from the wall, eventually you’ll arrive at the exit of the maze.
    */
    int *xPtr = &x;
    int *yPtr = &y;
    int checker, mazeResult;
    if (rightHasWall(maze, x, y, orientation))
    {
        if (frontHasPath(maze, x, y, orientation))
        {
            movement(maze, xPtr, yPtr, orientation);
            checker = checkPosition(*xPtr, *yPtr, xs, ys);
        }
        else
        {
            orientation = turnToLeft(orientation);
            checker = checkPosition(*xPtr, *yPtr, xs, ys);
        }
    }
    else
    {
        orientation = turnToRight(orientation);
        movement(maze, xPtr, yPtr, orientation);
        checker = checkPosition(*xPtr, *yPtr, xs, ys);
    }
    printMaze(maze, x, y);
    if (checker == -1)
    {
        mazeResult = mazeTraverse(maze, xs, ys, x, y, orientation);
    }
    else if (checker == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int checkPosition(const int x, const int y, const int xs, const int ys)
{
    bool atStart = x == xs && y == ys;
    if (atStart)
    {
        return 0;
    }
    else if (y == MAZE_SIZE - 1)
    {
        puts("WON");
        return 1;
    }
    else
    {
        return -1;
    }
}
void movement(char maze[MAZE_SIZE][MAZE_SIZE], int *const xPtr, int *const yPtr, const char orientation)
{
    int nextXValue = *xPtr;
    int nextYValue = *yPtr;
    switch (orientation)
    {
    case 'T':
        nextXValue = *xPtr - 1;
        break;
    case 'R':
        nextYValue = *yPtr + 1;
        break;
    case 'B':
        nextXValue = *xPtr + 1;
        break;
    case 'L':
        nextYValue = *yPtr - 1;
        break;
    }
    bool isValidX = nextXValue >= 0 && nextXValue < MAZE_SIZE;
    bool isValidY = nextYValue >= 0 && nextYValue < MAZE_SIZE;
    if (isValidX && isValidY)
    {
        maze[*xPtr][*yPtr] = 'X';
        *xPtr = nextXValue;
        *yPtr = nextYValue;
    }
}
char turnToRight(const char orientation)
{
    switch (orientation)
    {
    case 'T':
        return 'R';
        break;
    case 'R':
        return 'B';
        break;
    case 'B':
        return 'L';
        break;
    case 'L':
        return 'T';
        break;
    }
}
char turnToLeft(const char orientation)
{
    switch (orientation)
    {
    case 'T':
        return 'L';
        break;
    case 'R':
        return 'T';
        break;
    case 'B':
        return 'R';
        break;
    case 'L':
        return 'B';
        break;
    }
}
int frontHasPath(const char maze[MAZE_SIZE][MAZE_SIZE], const int x, const int y, const char orientation)
{
    if (orientation == 'R')
    {
        if (y + 1 < MAZE_SIZE)
        {
            return '.' == maze[x][y + 1];
        }
    }
    else if (orientation == 'B')
    {
        if (x + 1 < MAZE_SIZE)
        {
            return '.' == maze[x + 1][y];
        }
    }
    else if (orientation == 'T')
    {
        if (x - 1 >= 0)
        {
            return '.' == maze[x - 1][y];
        }
    }
    else
    {
        if (y - 1 >= 0)
        {
            return '.' == maze[x][y - 1];
        }
    }
    return 1;
}
int rightHasWall(const char maze[MAZE_SIZE][MAZE_SIZE], const int x, const int y, const char orientation)
{
    if (orientation == 'T')
    {
        if (y + 1 < MAZE_SIZE)
        {
            return '#' == maze[x][y + 1];
        }
    }
    else if (orientation == 'R')
    {
        if (x + 1 < MAZE_SIZE)
        {
            return '#' == maze[x + 1][y];
        }
    }
    else if (orientation == 'L')
    {
        if (x - 1 >= 0)
        {
            return '#' == maze[x - 1][y];
        }
    }
    else
    {
        if (y - 1 >= 0)
        {
            return '#' == maze[x][y - 1];
        }
    }
    return 1;
}
void printMaze(const char maze[MAZE_SIZE][MAZE_SIZE], const int x, const int y)
{
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            if (i == x && y == j)
            {
                printf("%c", 'P');
            }
            else
            {
                printf("%c", maze[i][j]);
            }
        }
        puts(" ");
    }
}