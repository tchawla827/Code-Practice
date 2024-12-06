#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter an Integer : ";
    cin>>n;

    if((n&(n-1))==0)
    {
        if(n%3==1)
        cout<<n<< " is a power of four"<<endl;
        else
        cout<<n<< " is not a power of four"<<endl;
    }
    else
    {
        cout<<n<< " is not a power of four"<<endl;
    }
}