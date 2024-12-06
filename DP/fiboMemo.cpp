#include <bits/stdc++.h>
using namespace std;

int cnt=0;
int fib(int n, vector<int> &memo)
{
    cnt++;
    if (n <= 2)
    {
        return memo[n]=1;
    }
    if (memo[n] != -1)
        return memo[n];

    return memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
}

int main()
{
    int n;
    cin >> n;
    vector<int> memo(n + 1, -1);
    fib(n, memo);
    for (int i = 1; i <= n; i++)
    {
        cout << memo[i] << " ";
    }
    cout << endl;
    cout<<cnt<<endl;
}