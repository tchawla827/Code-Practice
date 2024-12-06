#include<bits/stdc++.h>
using namespace std;

vector<int> memo;

int steps(int n)
{
    if(n==1) return memo[n];
    if(memo[n]!=-1) return memo[n];

    int ans=INT_MAX;
    if(n%2==0)
    ans=min(ans,steps(n/2));
    if(n%3==0)
    ans=min(ans,steps(n/3));
    ans=min(ans,steps(n-1));

    return memo[n]=ans+1;
}

int main()
{
    int n;
    cin>>n;
    memo.resize(n+1,-1);
    memo[1]=0;
    cout<<steps(n)<<endl;
    
}