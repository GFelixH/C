/*
(Guess the Number Modification) Modify the program of Exercise 5.32 to count the number of guesses the player makes. If the number is 10 or fewer, print Either you know the secret or
you got lucky! If the player guesses the number in 10 tries, then print Ahah! You know the secret!
If the player makes more than 10 guesses, then print You should be able to do better! Why should
it take no more than 10 guesses? Well, with each “good guess” the player should be able to eliminate
half of the numbers. Now show why any number 1 to 1000 can be guessed in 10 or fewer tries.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    // seed rand
    srand(time(NULL));

    int guess, random = 1 + rand() % 1001, tries = 0;
    bool gameContinue = true;

    printf("%d", random);

    while (gameContinue)
    {
        puts("Insert guess: ");
        scanf("%d", &guess);
        tries++;
        if (guess > random)
        {
            puts("Too high");
        }
        else if (guess < random)
        {
            puts("too low");
        }
        else
        {
            puts("Correct answer");
            gameContinue = false;
            printf("You tried %d times\n", tries);
            if (tries < 10)
            {
                puts("You got lucky or you know the secret...");
            }
            else if (tries == 10)
            {
                puts("You know the secret! XD");
            }
            else
            {
                puts("You should do better.");
            }
        }
    }
}