#include<stdio.h>

void perm2(int A[],int k, int n)
{
    static int B[10]={0};
    static int res[10];
    int i;

    if(k==n)
    {
        for(int i=0;i<n;i++)
        printf(" %d",res[i]);
        printf("\n");
    }
    else{
        for(i=0;i<n;i++)
        {
            if(B[i]==0)
            {
                res[k]=A[i];
                B[i]=1;
                perm2(A,k+1,n);
                B[i]=0;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int A[n];
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    perm2(A,0,n);
}