#include<bits/stdc++.h>
using namespace std;

vector<int> memo;
vector<int> prices;

int cutRod(int n)
{
    if(n==0) return 0;
    if(memo[n]!=-1) return memo[n];

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,cutRod(n-i)+prices[i]);
    }
    return memo[n]=ans;
}

int main()
{
    int n;
    cin>>n;
    memo.resize(n+1,-1);
    prices.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>prices[i];
    }
    cout<<cutRod(n)<<endl;
}