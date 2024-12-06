#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter an Integer : ";
    cin>>n;

    if((n&(n-1))==0)
    {
        cout<<n<< " is a power of two"<<endl;
    }
    else
    {
        cout<<n<< " is not a power of two"<<endl;
    }
}