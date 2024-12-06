#include<stdio.h>

void transfer(int n,int A,int B, int C)
{
    if(n>0)
    {
        transfer(n-1,A,C,B);
        printf("from %d to %d\n",A,C);
        transfer(n-1,B,A,C);
    }
}

int main()
{
    printf("Enter number of discs : ");
    int n;
    scanf("%d",&n);
    transfer(n,1,2,3);
}