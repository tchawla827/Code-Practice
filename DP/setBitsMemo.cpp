#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
int c = 0;
int setBits(int n)
{
    
    if (memo[n] != -1)
        return memo[n];

    if (n == 0)
        return memo[n] = 0;

    c++;
    if (n & 1)
        return memo[n] = setBits(n / 2) + 1;
    else
        return memo[n] = setBits(n / 2);
}

int main()
{
    int n;
    cin >> n;
    memo.resize(n + 1, -1);
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        setBits(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << memo[i] << endl;
    }
    cout << c << endl;
}