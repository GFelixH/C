/*
Bank Simulator Program
*/
#include <stdio.h>
typedef struct
{
    unsigned int id;
    double balance;
    char name[30];
} Customer;

FILE *openFile();
void createFile();
void printUsers();
void createUser();
int main(void)
{
    createFile();
    printUsers();
    createUser();
    printUsers();
    return 0;
}
void createUser()
{
    FILE *fPtr = openFile();
    Customer fillCustomer = {0, 0.0, ""};

    puts("Insert id, balance and name:");
    while (!feof(fPtr))
    {
        if (fillCustomer.id == 0)
        {
            scanf("%d%lf%29s", &fillCustomer.id, &fillCustomer.balance, &fillCustomer.name);
            fwrite(&fillCustomer, sizeof(Customer), 1, fPtr);
            break;
        }
        fread(&fillCustomer, sizeof(Customer), 1, fPtr);
    }
    fclose(fPtr);
}
void printUsers()
{
    FILE *fPtr = openFile();
    Customer fillCustomer = {0, 0.0, ""};

    fread(&fillCustomer, sizeof(Customer), 1, fPtr);
    while (!feof(fPtr))
    {
        printf("ID:%d Balance:%10.2lf Name:%s\n", fillCustomer.id, fillCustomer.balance, fillCustomer.name);
        fread(&fillCustomer, sizeof(Customer), 1, fPtr);
    }
}
void createFile()
{
    FILE *fPtr = fopen("customers2.dat", "wb");
    Customer fillCustomer = {0, 0.0, ""};
    for (int i = 0; i < 10; i++)
    {
        fwrite(&fillCustomer, sizeof(Customer), 1, fPtr);
    }
    fclose(fPtr);
}
FILE *openFile()
{
    return fopen("customers2.dat", "rb+");
}