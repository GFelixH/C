/*(File Matching)
Use the account number on each file as the record key for matching purposes.
Assume that each file is a sequential file with records stored in increasing account-number order.
*/
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
} Transaction;

int main(void)
{
    FILE *omPtr = fopen("master2.dat", "rb");
    FILE *tPtr = fopen("transaction2.dat", "rb");
    FILE *nmPtr = fopen("newmaster.dat", "wb+");
    Account streamAccount = {0, 0.0, ""};
    Transaction streamTransaction = {0, 0.0};

    if (omPtr != NULL && tPtr != NULL && nmPtr != NULL)
    {
        fread(&streamTransaction, sizeof(Transaction), 1, tPtr);
        fread(&streamAccount, sizeof(Account), 1, omPtr);

        while (!feof(omPtr) || !feof(tPtr))
        {
            if (feof(omPtr))
            {
                puts("Unmatched transaction record for account number…");
                Account updateAccount = {0, 0.0, ""};
                updateAccount.balance = streamTransaction.amount;
                updateAccount.id = streamTransaction.id;
                puts("Insert account name:");
                fgets(updateAccount.name, 30, stdin);
                fwrite(&updateAccount, sizeof(Account), 1, nmPtr);
                fread(&streamTransaction, sizeof(Transaction), 1, tPtr);
            }
            else if (feof(tPtr))
            {
                puts("No transaction");
                fwrite(&streamAccount, sizeof(Account), 1, nmPtr);
                fread(&streamAccount, sizeof(Account), 1, omPtr);
            }
            else if (streamAccount.id == streamTransaction.id)
            {
                // Match
                puts("Match");
                Account updateAccount = {0, 0.0, ""};
                updateAccount.balance = streamAccount.balance + streamTransaction.amount;
                updateAccount.id = streamAccount.id;
                strcpy(updateAccount.name, streamAccount.name);
                fread(&streamTransaction, sizeof(Transaction), 1, tPtr);
                // next transaction
                while (streamAccount.id == streamTransaction.id)
                {
                    puts("Match");
                    updateAccount.balance += streamTransaction.amount;
                    fread(&streamTransaction, sizeof(Transaction), 1, tPtr);
                }
                fwrite(&updateAccount, sizeof(Account), 1, nmPtr);
                fread(&streamAccount, sizeof(Account), 1, omPtr);
            }
            else if (streamAccount.id > streamTransaction.id)
            {
                puts("Unmatched transaction record for account number…");
                Account updateAccount = {0, 0.0, ""};
                updateAccount.balance = streamTransaction.amount;
                updateAccount.id = streamTransaction.id;
                puts("Insert account name:");
                fgets(updateAccount.name, 30, stdin);
                fwrite(&updateAccount, sizeof(Account), 1, nmPtr);
                fread(&streamTransaction, sizeof(Transaction), 1, tPtr);
            }
            else
            {
                puts("No transaction");
                fwrite(&streamAccount, sizeof(Account), 1, nmPtr);
                fread(&streamAccount, sizeof(Account), 1, omPtr);
            }
        }

        fclose(omPtr);
        fclose(tPtr);

        rewind(nmPtr);

        fread(&streamAccount, sizeof(Account), 1, nmPtr);
        while (!feof(nmPtr))
        {
            printf("%d %.2lf %s\n", streamAccount.id, streamAccount.balance, streamAccount.name);
            fread(&streamAccount, sizeof(Account), 1, nmPtr);
        }
    }

    return 0;
}