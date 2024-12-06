#include<bits/stdc++.h>
using namespace std;

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
}


