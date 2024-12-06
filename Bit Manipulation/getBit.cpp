#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int i)
{
    int mask=1<<i;
    if((mask & n)!=0) return 1;
    return 0;
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
    int i;
    cout<<"Enter Index of Bit : ";
    cin>>i;
    cout<<"Bit is : "<<getBit(n,i);
}