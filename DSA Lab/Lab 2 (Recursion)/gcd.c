#include<stdio.h>

int gcd (int a, int b)
{
    if(b==0)
    return a;
    else{
        gcd(b,a%b);
    }
}

int main()
{
    int a,b;
    printf("Enter first integer : ");
    scanf("%d",&a);
    printf("Enter second integer : ");
    scanf("%d",&b);
    printf("Greatest common divisor of %d and %d = %d\n",a,b,gcd(a,b));
}