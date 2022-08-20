#include <stdio.h>
#include <string.h>
typedef struct
{
    int id;
    double balance;
    char name[30];
} Account;
typedef struct
{
    int id;
    double amount;
} Transcation;
int main(void)
{
    FILE *fPtr = fopen("master2.dat", "wb");
    for (int i = 0; i < 4; i++)
    {
        Account fillAccount = {0, 0.0, ""};
        puts("Insert Account Data: ID BALANCE");
        scanf("%d %lf%*c", &fillAccount.id, &fillAccount.balance);
        puts("Insert Account Data: NAME");
        fgets(fillAccount.name, 30, stdin);
        fwrite(&fillAccount, sizeof(Account), 1, fPtr);
    }
    fclose(fPtr);

    FILE *fPtr2 = fopen("transaction2.dat", "wb");
    for (int i = 0; i < 7; i++)
    {
        Transcation fillTranscation = {0, 0.0};
        puts("Insert Balance:");
        scanf("%d %lf", &fillTranscation.id, &fillTranscation.amount);
        fwrite(&fillTranscation, sizeof(Transcation), 1, fPtr2);
    }
    fclose(fPtr2);

    return 0;
}