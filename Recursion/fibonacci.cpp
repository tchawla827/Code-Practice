#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    int *fib=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        fib[i]=0;
    }
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
}

int fibonacci2(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;

    return fibonacci2(n-1)+fibonacci2(n-2);
}


int main()
{
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    cout<<fibonacci2(n)<<endl;
}