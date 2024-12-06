#include<bits/stdc++.h>
using namespace std;

bool isEven(int &n)
{
    if((n&1)==0) return true;
    return false;
}

int main()
{
    int n;
    cout<<"Enter an Integer : ";
    cin>>n;
    if(isEven(n))
        cout<<n<<" is even"<<endl;
    else
        cout<<n<<" is odd"<<endl;
}