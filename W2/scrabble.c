// SCRABBLE
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int scrabble(char *word);

int main(void)
{
    int p1 = 0, p2 = 0;
    char player1[] = "";
    char player2[] = "";

    fflush(stdin);
    puts("INSERT PLAYER 1 WORD!");
    fgets(player1, 100, stdin);
    fflush(stdin);
    puts("INSERT PLAYER 2 WORD!");
    fgets(player2, 100, stdin);

    p1 = scrabble(player1);
    p2 = scrabble(player2);

    if (p1 > p2)
    {
        puts("PLAYER 1 WINS !!!");
    }
    else if (p1 == p2)
    {
        puts("PLAYER 2 WINS !!!");
    }
    else
    {
        puts("IT'S A TIE !!!");
    }
    return 0;
}
int scrabble(char *word)
{
    int points = 0, POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0; i < strlen(word); i++)
    {
        int currentChar = ((int)toupper(word[i])) - 65;
        if (currentChar >= 65 && currentChar <= 90)
        {
            points += POINTS[currentChar];
        }
    }
    return points;
}