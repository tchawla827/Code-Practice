//given 2n+1 numbers, find number which comes only once, others come twice.
#include<bits/stdc++.h>
using namespace std;

int uniqueNumber(vector<int> a)
{
    int cum_xor=0;
    for(auto x:a)
    {
        cum_xor=cum_xor^x;
    }
    return cum_xor;
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
    cout<<"Unique Number : "<<uniqueNumber(a)<<endl;
}