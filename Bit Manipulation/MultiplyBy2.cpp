#include<bits/stdc++.h>
using namespace std;

int multiplyby2(int n,int m)
{
    n=(n<<m);
    return n;
}

int main()
{
    int n;
    cout<<"Enter an Integer : ";
    cin>>n;
    int m;
    cout<<"How many times to multiply two : ";
    cin>>m;
    cout<<n<<" multiplied with two "<<m<<" times gives : "<<multiplyby2(n,m);
}