#include<bits/stdc++.h>
using namespace std;

int divideby2(int n,int m)
{
    n=(n>>m);
    return n;
}

int main()
{
    int n;
    cout<<"Enter an Integer : ";
    cin>>n;
    int m;
    cout<<"How many times to divide two : ";
    cin>>m;
    cout<<n<<" divided with two "<<m<<" times gives : "<<divideby2(n,m);
}