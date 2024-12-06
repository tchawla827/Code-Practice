//IIT2023150 Tavish Chawla
#include<stdio.h>

int biggestnum(int A[], int n, int i)
{
    static int max;
    if(i==n)
    return max;
    else{
        if(A[i]>max)
        max=A[i];
        return biggestnum(A,n,i+1);
    }
}

int main()
{
    printf("ENTER SIZE OF ARRAY : ");
    int n;
    scanf("%d",&n);
    int A[n];
    printf("ENTER ELEMENTS\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Largest number = %d\n",biggestnum(A,n,0));
}