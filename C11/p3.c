/*
(Telephone-Number Word Generator) Standard telephone keypads contain the digits 0–9.
*/
#include <stdio.h>

int main(void)
{
    char letters[10][3] = {
        {'\0', '\0', '\0'},
        {'\0', '\0', '\0'},
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'},
        {'J', 'K', 'L'},
        {'M', 'N', 'O'},
        {'P', 'R', 'S'},
        {'T', 'U', 'V'},
        {'W', 'X', 'Y'},
    };
    char input[9] = "";
    int numbers[8] = {0};
    char texts[2187][8];
    char a, b, c, d, e, f, g;
    int textPosition = 0;

    puts("Insert number in the format xxx-xxxx :");
    fgets(input, 9, stdin);
    input[8] = '\0';

    sscanf(input, " %1d %1d %1d - %1d %1d %1d %1d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5], &numbers[6]);

    for (int i = 0; i < 3; i++)
    {
        a = letters[numbers[0]][i];
        for (int j = 0; j < 3; j++)
        {
            b = letters[numbers[1]][j];
            for (int k = 0; k < 3; k++)
            {
                c = letters[numbers[2]][k];
                for (int l = 0; l < 3; l++)
                {
                    d = letters[numbers[3]][l];
                    for (int m = 0; m < 3; m++)
                    {
                        e = letters[numbers[4]][m];
                        for (int n = 0; n < 3; n++)
                        {
                            f = letters[numbers[5]][n];
                            for (int o = 0; o < 3; o++)
                            {
                                g = letters[numbers[6]][o];
                                texts[textPosition][0] = a;
                                texts[textPosition][1] = b;
                                texts[textPosition][2] = c;
                                texts[textPosition][3] = d;
                                texts[textPosition][4] = e;
                                texts[textPosition][5] = f;
                                texts[textPosition][6] = g;
                                texts[textPosition][7] = '\0';
                                textPosition++;
                            }
                        }
                    }
                }
            }
        }
    } // text processgin loops
    for (int i = 0; i < 2187; i++)
    {
        printf("%s ", &texts[i][0]);
        if (i % 12 == 0)
        {
            puts(" ");
        }
    }
    return 0;
}
