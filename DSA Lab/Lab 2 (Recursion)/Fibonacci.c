#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main()
{
    int n;
    printf("Enter positive integer : ");
    scanf("%d",&n);
    printf("The %d term of fibonacci sequence = %d\n", n,fib(n));
}