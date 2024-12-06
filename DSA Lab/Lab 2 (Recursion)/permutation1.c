#include<stdio.h>

void perm1(int A[],int l, int h)
{
    int i;
    if(l==h)
    {
        for(int i=0;i<=h;i++)
        printf(" %d",A[i]);
        printf("\n");
    }
    else{
        for(i=l;i<=h;i++)
        {
            int temp=A[l];
            A[l]=A[i];
            A[i]=temp;

            perm1(A,l+1,h);

             temp=A[l];
            A[l]=A[i];
            A[i]=temp;
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
    perm1(A,0,n-1);
}