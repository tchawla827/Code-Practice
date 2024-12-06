#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int dectobin(int a) {
    if (a == 0) {
        return 0;
    }

    int n = 0;
    int c = 0;

    while (a > 0) {
        if (a % 2 == 0) {
            c++; 
        } else {
            n = n * 10 + a % 2;
        }
        a = a / 2;
    }

    
    while (c > 0) {
        n = n * 10;
        c--;
    }

    return n;
}

int* inttoarr(int a)
{
    int *p=(int *)malloc(32*sizeof(int));
    for(int i=0;i<32;i++)
    {
        p[i]=0;
    }
    int i=0;
    while(a>0)
    {
        p[i]=a%10;
        i++;
        a/=10;
    }
    for(int j=0;j<16;j++)
    {
        int t=p[j];
        p[j]=p[31-j];
        p[31-j]=t;
    }
    return p;
}

void comp1(int A[])
{
    for(int i=0;i<32;i++)
    {
        if(A[i]==0)
        A[i]=1;
        else if(A[i]==1)
        A[i]=0;
    }
}

void comp2(int A[])
{
    int i=0;
    if(A[31]==0)
    A[0]=1;
    
    else if(A[31]==1)
    {
        while(A[31-i]==1)
        {
            A[31-i]=0;
            i++;
        }
        A[31-i]=1;
    }
}



int main()
{
    printf("ENTER AN INTEGER : ");
    int a;
    scanf("%d",&a);
    int b=dectobin(a);
    int *p=inttoarr(b);
    printf("BINARY OUTPUT :\n");
    for(int i=0;i<32;i++)
    {
        printf("%d",p[i]);
    }
    comp1(p);
    printf("\nAFTER 1's COMPLEMENT :\n");
    for(int i=0;i<32;i++)
    {
        printf("%d",p[i]);
    }
    comp2(p);
    printf("\nAFTER 2's COMPLEMENT :\n");
    for(int i=0;i<32;i++)
    {
        printf("%d",p[i]);
    }



}
