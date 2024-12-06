

#include <stdio.h>

int main()
{
    int num1, num2;
    printf("\nEnter two numbers to perform addition and subtraction using bitwise operators: ");
    scanf("%d%d", &num1, &num2);

    int x1 = num1;
    int y1 = num2;
    int x2 = num1;
    int y2 = num2;

    while (y1 != 0)
    {
        int carry = x1 & y1;
        x1 = x1 ^ y1;
        y1 = carry << 1;
    }
    printf("\nSum is %d", x1);

    while (y2 != 0)
    {
        int borrow = (~x2) & y2;
        x2 = x2 ^ y2;
        y2 = borrow << 1;
    }

    printf("\ndifference = %d", x2);
    return 0;
}