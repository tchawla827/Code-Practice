#include<iostream>
using namespace std;

void Merge(int *A,int l,int mid,int h)
{
    int i=l;
    int k=0;
    int j=mid+1;
    int *B=new int[(h-l)+1];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        if(A[i]>A[j])
        {
            B[k++]=A[j++];
        }
    }
   while(i<=mid)
   {
    B[k++]=A[i++];
   }  
   while(j<=h)
   {
    B[k++]=A[j++];
   }
   
    k=0;
    for(int i=l;i<=h;i++)
    {
        A[i]=B[k++];
    }
}
void MergeSort(int *A, int l, int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout<<"Enter size of Array : ";
    cin>>n;
    int *A=new int [n];
    cout<<"Enter Elements\n";
    for(int i=0;i<n;i++)
    cin>>A[i];

    cout<<"Array before sorting : ";
    display(A,n);

    MergeSort(A,0,n-1);
    
    cout<<"Array after sorting : ";
    display(A,n);
}