#include<bits/stdc++.h>
using namespace std;

int toBinary(int n)
{
    int ans=0;
    int pow=1;
    
    while(n)
    {
        int lastbit=n&1;
        ans+=(lastbit)*pow;
        n=n>>1;
        pow*=10;
    }
    return ans;
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

    cout<<endl<<"BINARY : "<<toBinary(n)<<endl;
}