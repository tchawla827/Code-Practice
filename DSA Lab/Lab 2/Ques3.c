//IIT2023150 Tavish Chawla
#include <stdio.h>

int multiply(int a, int b, int i, int res)
{
    if (i == b)
    {
        return res;
    }
    else
    {
        res += a;
        i++;
        return multiply(a, b, i, res);
    }
}

int main()
{
    printf("Enter first integer : ");
    int a,b;
    scanf("%d",&a);
    printf("Enter second integer : ");
    scanf("%d",&b);
    int c=multiply(a,b,0,0);
    printf("the product = %d\n",c);
}