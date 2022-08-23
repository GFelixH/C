/*
14.5 (Signal Handling) Read the documentation for your compiler to determine what signals
are supported by the signal-handling library (<signal.h>). Write a program that contains signal
handlers for the standard signals SIGABRT and SIGINT. The program should test the trapping of these
signals by calling function abort to generate a signal of type SIGABRT and by having the user type
<Ctrl> c (<control> C on OS X) to generate a signal of type SIGINT.
*/
#include <stdio.h>
#include <signal.h>
void sigabort();
void sigint();
int main(void)
{
    signal(SIGABRT, sigabort);
    signal(SIGINT, sigint);
    getchar();
    raise(SIGABRT);
    raise(SIGINT);
    return 0;
}
void sigabort()
{
    puts("SIGNAL ABORTION DETECTED");
}
void sigint()
{
    puts("SIGNAL INTERRUPT DETECTED");
}