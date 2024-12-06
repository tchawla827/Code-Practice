#include<iostream>
using namespace std;

void selectionSort(int *A, int n)
{
    int i;
    int j,k;
    for(int i=0;i<n-1;i++)
    {
        for(int j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
            {
                k=j;
            }
        }
        swap(A[i],A[k]);
    }

}

void display(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
    }
    cout<<endl;
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

    selectionSort(A,n);
    
    cout<<"Array after sorting : ";
    display(A,n);
}