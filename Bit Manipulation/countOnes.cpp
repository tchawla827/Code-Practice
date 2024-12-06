#include<bits/stdc++.h>
using namespace std;

void displayBITS(int n)
{
    for(int i=31;i>=0;i--)
    {
        cout<<((n>>i)&1);
    }
}

int countOnes(int n)
{
    int ct=0;
    while(n>0)
    {
        if(n&1)
        ct++;
        n=n>>1;
    }
    return ct;
}

int main()
{
    int n;
    cout<<"Enter an Integer : ";
    cin>>n;
    cout<<"Number of set bits : "<<countOnes(n)<<endl;
    cout<<"bits : ";
    displayBITS(n);
    cout<<endl;
}