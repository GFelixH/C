/*
11.12 (Hardware Inventory)lets you input the data concerning
each tool, enables you to list all your tools, lets you delete a record for a tool that you no longer have and lets you update any information in the file. The tool identification number should be the record
number. Use the following information to start your file:
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned int record;
    unsigned int quantity;
    double cost;
    char toolName[20];
} Tool;

char file[] = "inventory.dat";

void printFile();
void createFile();
int response();
void addTool();
void removeTool();

int main(void)
{
    enum state
    {
        STOP,
        CONTINUE
    };
    enum state myState = CONTINUE;
    int option;

    createFile();

    printf("%s", "*******************\n|     WELCOME     |\n*******************\n");
    while (myState)
    {
        option = response();
        switch (option)
        {
        case 1:
            addTool();
            break;
        case 2:
            removeTool();
            break;
        case 3:
            addTool();
            break;
        case 4:
            printFile();
            break;
        case 5:
            myState = STOP;
            puts("Good-Bye! XD");
            break;
        default:
            puts("ERROR: INVALID OPTION");
            return 1;
        }
    }
    return 0;
}
void removeTool()
{
    FILE *F = fopen(file, "rb+");
    if (F == NULL)
    {
        puts("ERROR READING FILE");
    }
    else
    {
        int x;
        Tool defaultTool = {0, 0, 0.0, ""};
        printf("%s", "Insert tool id: ");
        scanf("%d%*c", &x);
        fseek(F, x * sizeof(Tool), SEEK_SET);
        fwrite(&defaultTool, sizeof(Tool), 1, F);
    }
    fclose(F);
}
void addTool()
{
    FILE *F = fopen(file, "rb+");
    if (F == NULL)
    {
        puts("ERROR READING FILE");
    }
    else
    {
        int x;
        Tool inputTool = {0, 0, 0.0, ""};
        printf("%s", "Insert tool id: ");
        scanf("%d%*c", &x);
        inputTool.record = x;
        fseek(F, x * sizeof(Tool), SEEK_SET);

        puts("Insert tool name:");
        fgets(inputTool.toolName, 20, stdin);
        inputTool.toolName[strlen(inputTool.toolName) - 1] = '\0';
        printf("%s", "Insert tool quantity: ");
        scanf("%u%*c", &inputTool.quantity);
        printf("%s", "Insert tool cost: ");
        scanf("%lf%*c", &inputTool.cost);
        printf("%d %u %lf %s", inputTool.record, inputTool.quantity, inputTool.cost, inputTool.toolName);
        fwrite(&inputTool, sizeof(Tool), 1, F);
    }
    fclose(F);
}
int response()
{
    int x = 0;
    printf("%s", "Select:\n 1 to add toll\n 2 to remove tool\n 3 to update tool\n 4 to list tools\n 5 to stop\n?");
    scanf("%d[12345]", &x);
    if (x)
    {
        return x;
    }
    else
    {
        puts("Incorrect option");
        return response();
    }
}
void printFile()
{
    FILE *F = fopen(file, "rb");
    if (F == NULL)
    {
        puts("ERROR READING FILE");
    }
    else
    {
        puts("Record #  Tool name           Quantity   Cost  ");
        Tool streamTool = {0, 0, 0.0, ""};
        fread(&streamTool, sizeof(Tool), 1, F);
        while (!feof(F))
        {
            printf("%-8hd  %-20s%-8d%7.2lf\n", streamTool.record, streamTool.toolName, streamTool.quantity, streamTool.cost);
            fread(&streamTool, sizeof(Tool), 1, F);
        }
    }
    fclose(F);
}
void createFile()
{
    FILE *F = fopen(file, "wb");
    if (F == NULL)
    {
        puts("ERROR READING FILE");
    }
    else
    {
        Tool fillTool = {0, 0, 0.0, ""};
        for (int i = 0; i < 100; i++)
        {
            fillTool.record = i;
            fwrite(&fillTool, sizeof(Tool), 1, F);
        }
    }
    fclose(F);
}