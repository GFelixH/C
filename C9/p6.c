/*
9.11 (Escape Sequences) Write a program to test the escape sequences \', \", \?, \\, \a, \b, \n,
\r and \t. For the escape sequences that move the cursor, print a character before and after printing
the escape sequence so it’s clear where the cursor has moved.
*/
#include<stdio.h>

int main(void){
    puts("++\a++");
    puts("++\b++");
    puts("++\n++");
    puts("++\r++");
    puts("++\t++");
    
    
    return 0;
}