//IIT2023150 Tavish Chawla
#include<stdio.h>

void perm2(int A[],int k, int n,int r)
{
    static int B[10]={0};
    static int res[10];
    int i;

    if(k==r)
    {
        for(int i=0;i<r;i++)
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
                perm2(A,k+1,n,r);
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
    int r;
    printf("Enter value of r: ");
    scanf("%d", &r);
    perm2(A,0,n,r);
}