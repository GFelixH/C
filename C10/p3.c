/*
10.6
*/
#include <stdio.h>
int main(void)
{
    struct customer
    {
        char lastName[15];
        char firstName[15];
        unsigned int customerNumber;
        struct
        {
            char phoneNumber[11];
            char address[50];
            char city[15];
            char state[3];
            char zipCode[6];
        } personal;
    } customerRecord, *customerPtr;
    customerPtr = &customerRecord;
    // customerRecord.lastname
    // customerPtr->lastname
    // customerRecord.personal.phoneNumber;
    // customerPtr->personal.phoneNumber
    return 0;
}