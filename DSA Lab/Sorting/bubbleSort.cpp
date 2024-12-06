#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbbleSort(int A[], int n)
{
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                flag=1;
            }

        }
        if(flag==0)
        {
            break;
        }
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

    bubbbleSort(A,n);
    
    cout<<"Array after sorting : ";
    display(A,n);
}