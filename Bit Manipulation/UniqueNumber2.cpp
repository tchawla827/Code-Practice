//given 2n+2 numbers, find two number which comes only once, others come twice.
#include<bits/stdc++.h>
using namespace std;

void uniqueNumber(vector<int> a)
{
    int total=0;
    for(auto x:a)
    {
        total=total^x;
    }

    int pos=0;
    int temp=total;
    
    while(temp&1==0)
    {
        pos++;
        temp=temp>>1;
    }

    int mask=1<<pos;

    int setA=0;
    int setB=0;

    for(auto x:a)
    {
        if(x&mask)
        setA=setA^x;
        else
        setB=setB^x;
    }

    cout<<"Unique Number 1: "<<setA<<endl;
    cout<<"Unique Number 2: "<<setB<<endl;
    
}

int main()
{
    int n;
    cout<<"How many Integers : ";
    cin>>n;
    vector<int>a ;

    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.push_back(x);
    }
    uniqueNumber(a);
    
}