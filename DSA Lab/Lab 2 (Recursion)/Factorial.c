#include<stdio.h>
#include<stdlib.h>

int fact(int n)
{
    if(n==1 || n==0)
    return 1;
    else 
    return fact(n-1)*n;
}

int main()
{
    printf("Enter A Positive Integer : ");
    int x;
    scanf("%d",&x);
    if(x<0)
    {printf("Enter a valid positive integer\n");
    exit(1);}
    int res=fact(x);
    printf("Factorial of %d = %d\n",x,res);
    
}