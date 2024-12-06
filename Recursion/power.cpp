#include<bits/stdc++.h>
using namespace std;

int power(int base, int pow)
{
    if(pow==0)
    {
        return 1;
    }
    return base*power(base,pow-1);
}

int power2(int base,int pow)
{
    if(pow==0)
    {
        return 1;
    }
    int subP=power2(base,pow/2);
    if(pow&1)
    {
        return subP*subP*base;
    }
    else
    {
        return subP*subP;
    }

}

int main()
{
    int a,n;
    cin>>a>>n;
    cout<<power(a,n)<<endl;
    cout<<power2(a,n)<<endl;
}