#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *A,int n)
{
    if(n==1) return true;
    if(A[n-1]>=A[n-2]) return isSorted(A,n-1);
    return false;
}

int main()
{
    int n;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    cout<<isSorted(A,n)<<endl;
}