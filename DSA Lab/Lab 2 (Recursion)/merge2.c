#include <stdio.h>
#include <stdlib.h>
//merge two sorted lists in one array

int * merge(int A[], int l, int mid , int h)
{
    int i=l,j=mid+1,k=0;
    int *C=(int *)malloc((h+1)*sizeof(int));

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
        {
            C[k++]=A[i++];
        }
        else{
            C[k++]=A[j++];
        }
    }
    while(i<=mid)
    C[k++]=A[i];
    while(j<=h)
    C[k++]=A[j++];
    return C;
}

int main()
{
    int i=0;
    int l1,l2;
    printf("Enter Size of List 1 : ");
    scanf("%d",&l1);
    printf("Enter Size of List 2 : ");
    scanf("%d",&l2);
    int A[l1+l2];
    printf("\nEnter Elements of List 1 :\n"); //list is already sorted!
    for(;i<l1;i++)
    scanf("%d",&A[i]);
    printf("\nEnter Elements of List 2 :\n"); //list is already sorted!
    for(;i<l2+l1;i++)
    scanf("%d",&A[i]);
    
    printf("\nArray : ");
    for(int i=0;i<l1+l2;i++)
    printf("%d ", A[i]);

    int *P=merge(A,0,l1-1,l1+l2-1);
    printf("\nSorted Array : ");
    for(int i=0;i<l1+l2;i++)
    printf("%d ",P[i]);

}

