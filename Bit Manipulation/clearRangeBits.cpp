#include<bits/stdc++.h>
using namespace std;

void displayBITS(int n)
{
    for(int i=31;i>=0;i--)
    {
        cout<<((n>>i)&1);
    }
}

void clearRange(int &n, int i, int j) 
{
    int allOnes = ~0; 

    int left = allOnes << (i + 1); 
    int right = (1 << j) - 1; 

    int mask = left | right; 
    n = n & mask; 
}

int main()
{
    int n;
    int i,j;
    cout<<"Enter Number : ";
    cin>>n;

    cout<<"bits : ";
    displayBITS(n);
    cout<<endl;

    cout<<"Enter Range : ";
    cin>>i>>j;

    clearRange(n,max(i,j),min(i,j));

    cout<<"bits : ";
    displayBITS(n);
    cout<<endl;

}