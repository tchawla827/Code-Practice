#include<bits/stdc++.h>
using namespace std;

int clearLastBits(int &n, int i)
{
    int mask=(-1)<<i;
    n=n&mask;
}

void displayBITS(int n)
{
    for(int i=31;i>=0;i--)
    {
        cout<<((n>>i)&1);
    }
}

int main()
{
    int n;
    cout<<"Enter Integer : ";
    cin>>n;

    cout<<"bits : ";
    displayBITS(n);
    cout<<endl;

    int i;
    cout<<"\nEnter Index of Bit : ";
    cin>>i;

    clearLastBits(n,i);
    cout<<"\nLast "<<i<<" Bits are cleared\n";

    cout<<"bits : ";
    displayBITS(n);
    cout<<endl;
    
}