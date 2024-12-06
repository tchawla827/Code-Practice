#include<bits/stdc++.h>
using namespace std;

void Insert(int * A, int n)
{
    int x=A[n];
    int i=n;
    while(i>1 && x>A[i/2])
    {
        int temp=A[i/2];
        A[i/2]=x;
        A[i]=temp;

        i=i/2;
    }
}

int * createHeap(int n)
{
    
    int *A=new int[n+1];
    cout<<"\nEnter Elements :  ";
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }

    for(int i=2;i<=n;i++)
    {
        Insert(A,i);
    }

    return A;
}

int main()
{
    int n;
    cout<<"\nEnter Number Of Elements : ";
    cin>>n;
    int * A=createHeap(n);
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<A[i]<<" ";
    }
}