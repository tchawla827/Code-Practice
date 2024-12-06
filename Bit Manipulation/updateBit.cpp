#include<bits/stdc++.h>
using namespace std;

 void clearBit(int &n, int i)
{
    int mask=~0;
    mask=(mask^(1<<i));
    n=n&mask;
}

void updateBit(int &n, int i,int v)
{
    clearBit(n,i);
    int mask=v<<i;
    n=n|mask;
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

    int v;
    cout<<"\nEnter 0/1 : ";
    cin>>v;

    updateBit(n,i,v);
    if(v==0)
    cout<<"\nBit is cleared\n";
    else
    cout<<"\nBit is set\n";

    cout<<"bits : ";
    displayBITS(n);
    cout<<endl;

    cin>>n;
    
}