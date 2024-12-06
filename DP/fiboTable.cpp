#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    vector<int> fibo(n,0);
    fibo[0]=fibo[1]=1;
    for(int i=2;i<n;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-1];
    }
    return fibo[n-1];
}

int main()
{
    int n;
    cin >> n;
    
    cout<<fib(n)<<endl;
}