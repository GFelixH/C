/*
(Guess the Number) Write a C program that plays the game of “guess the number” as follows: Your program chooses the number to be guessed by selecting an integer at random in the range
1 to 1000. The program then types:
I have a number between 1 and 1000.
Can you guess my number?
Please type your first guess
The player then types a first guess. The program responds with one of the following:
If the player’s guess is incorrect, your program should loop until the player finally gets the number
right. Your program should keep telling the player Too high or Too low to help the player “zero in”
on the correct answer. [Note: The searching technique employed in this problem is called binary
search. We’ll say more about this in the next problem.]
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    //seed rand
    srand(time(NULL));

    int guess, random = 1 + rand() % 1001;
    bool gameContinue = true;

    printf("%d", random);

    while(gameContinue){
        puts("Insert guess: ");
        scanf("%d", &guess);

        if(guess > random){
            puts("Too high");
        }else if(guess < random){
            puts("too low");
        }else{
            puts("Correct answer");
            gameContinue = false;
        }
    }
    
}
