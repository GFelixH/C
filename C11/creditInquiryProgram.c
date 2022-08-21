/*
The program of Fig. 11.7 allows a credit manager to obtain lists of customers with zero
balances (i.e., customers who do not owe any money), customers with credit balances (i.e.,
customers to whom the company owes money) and customers with debit balances (i.e.,
customers who owe the company money for goods and services received). A credit balance
is a negative amount; a debit balance is a positive amount.
The program displays a menu and allows the credit manager to enter one of four
options:
*/
#include <stdio.h>
#include <string.h>

void requireOption();
void createFile();
void balances();
void addCustomer();

typedef struct
{
    unsigned int account;
    double balance;
    char name[30];
} Customer;

int main(void)
{
    short int option = 5;

    createFile();
    while (option != 4)
    {
        requireOption();
        scanf("%hd", &option);
        switch (option)
        {
        case 1:
            balances();
            break;
        case 2:
            // addCustomer();
            FILE *fPtr;
            fPtr = fopne("customers,dat", "rb+");
            int a;
            double d;
            char name[30] = "";
            puts("Isert id balance and name");
            scanf("%d%lf%29s", &a, &d, name);
            Customer myInput = {a, d, name};
            Customer stream = {0, 0.0, ""};
            fread(&stream, sizeof(Customer), 1, fPtr);
            while (!feof(fPtr))
            {
                fread(&stream, sizeof(Customer), 1, fPtr);
            }

            break;
        case 3:
            // debitBalances();
            break;
        case 4:
            break;
        default:
            puts("Invalid input!!! >:(");
        }
    }
}
void addCustomer()
{
    FILE *fPtr = fopen("customers.dat", "rb+");
    if (fPtr == NULL)
    {
        ;
    }
    else
    {
        int id;
        double d;
        char name2[30] = "";
        Customer streamCustomer = {0, 0.0, ""};

        puts("Inser User id: ");
        scanf("%d", &id);
        fread(&streamCustomer, sizeof(Customer), 1, fPtr);

        while (!feof(fPtr))
        {
            if (streamCustomer.account == 0) // Empty user
            {
                Customer input = {0, 0.0, ""};
                puts("Insert Balance and Name");
                scanf("%lf %29s", &d, name2);
                input.balance = d;
                strcpy(input.name, name2);
                fwrite(&input, sizeof(Customer), 1, fPtr);
                break;
            }
            fread(&streamCustomer, sizeof(Customer), 1, fPtr);
        }
        fclose(fPtr);
    }
}
void createFile()
{
    // Creates empty file
    FILE *fPtr = fopen("customers.dat", "wb");
    // Default struct for initialization
    Customer initializer = {0, 0.0, ""};
    // Initialize it for 5 customers
    for (size_t i = 0; i < 10; i++)
    {
        fwrite(&initializer, sizeof(Customer), 1, fPtr);
    }
    fclose(fPtr);
}
void balances()
{
    FILE *cstPtr = fopen("customers.dat", "rb");
    Customer streamCustomer = {0, 0.0, ""};

    fread(&streamCustomer, sizeof(Customer), 1, cstPtr);
    while (!feof(cstPtr))
    {
        printf("Customer %-2d : %.2lf %s\n", streamCustomer.account, streamCustomer.balance, streamCustomer.name);
        fread(&streamCustomer, sizeof(Customer), 1, cstPtr);
    }
    puts(" ");
    fclose(cstPtr);
}
void requireOption()
{
    printf("%s\n\n", "• Option 1 produces a list of accounts.\n• Option 2 Add a customer\n• Option 3 produces a list of  with debit balances.\n• Option 4 terminates program execution");
}