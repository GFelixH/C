#include <stdio.h>
typedef struct
{
    unsigned int record;
    unsigned int quantity;
    double cost;
    char toolName[20];
} Tool;
int main(void)
{
    puts("Record #  Tool name           Quantity   Cost");
    Tool streamTool = {2, 2, 2.0, "test"};
    printf("%-8hd  %-20s%-8d %5.2lf\n", streamTool.record, streamTool.toolName, streamTool.quantity, streamTool.cost);
    Tool streamTool2 = {20, 2, 2.0, "test"};
    printf("%-8hd  %-20s%-8d %5.2lf\n", streamTool2.record, streamTool2.toolName, streamTool2.quantity, streamTool2.cost);
    return 0;
}