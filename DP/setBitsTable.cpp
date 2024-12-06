#include<bits/stdc++.h>
using namespace std;

void setBits(int n)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i/2]+(i&1);
        cout<<dp[i]<<endl;
    }
    
}

int main()
{
    int n;
    cin>>n;
    cout<<endl;
    setBits(n);
}