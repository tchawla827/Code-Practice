#include<stdio.h>
int main()
{
    printf("ENTER TWO INTEGERS : ");
    int x,y;
    scanf("%d%d",&x,&y);
    while (y != 0)
    {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    
    printf("x - y is %d", x);
    return 0;
}
