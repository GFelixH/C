/*
8.11 (Random Sentences) Write a program that uses random-number generation to create sentences. The program should use four arrays of pointers to char called article, noun, verb and preposition.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
#define MAX_SIZE 100

int randomNumber();
char *getNouns();
char *getArticles();
char *getVerbs();
char *getPrepositions();
void addsSpace(char *base);
void addsPoint(char *base);
void randomText(char *base);

int main(void)
{
    // Seeds the randomizer
    srand(time(NULL));

    char myString[MAX_SIZE] = {};

    randomText(myString);
    puts(myString);

    return 0;
}
void randomText(char *base)
{
    base = strcat(base, getArticles());
    addsSpace(base);
    base = strcat(base, getNouns());
    addsSpace(base);
    base = strcat(base, getVerbs());
    addsSpace(base);
    base = strcat(base, getPrepositions());
    addsSpace(base);
    base = strcat(base, getArticles());
    addsSpace(base);
    base = strcat(base, getNouns());
    addsPoint(base);
}
void captalizes(char *base)
{
    base[0] = toupper(base[0]);
}
void addsPoint(char *base)
{
    size_t size = strlen(base);
    puts("SIZE - 1 \n");
    printf("%c", base[size]);
    puts("SIZE \n");
    printf("%c", base[size + 1]);
    base[size] = '.';
    base[size + 1] = '\0';
}
void addsSpace(char *base)
{
    strcat(base, " ");
}
int randomNumber()
{
    return rand() % 5;
}
char *getNouns()
{
    char *nouns[SIZE] = {"boy", "girl", "dog", "town", "car"};
    return nouns[randomNumber()];
}
char *getArticles()
{
    char *articles[SIZE] = {"the", "a", "one", "some", "any"};
    return articles[randomNumber()];
}
char *getVerbs()
{
    char *verbs[SIZE] = {"drove", "jumped", "ran", "walked", "skipped"};
    return verbs[randomNumber()];
}
char *getPrepositions()
{
    char *prepositions[SIZE] = {"to", "from", "over", "under", "on"};
    return prepositions[randomNumber()];
}
