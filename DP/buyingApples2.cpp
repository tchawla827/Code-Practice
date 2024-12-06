#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int min(int a, int b)
{
    return a < b ? a : b;
}
int func(int n, int i, vvi &dp, vi &arr)
{
    int x, y;
    if (n < 0 || i == 0 && n)
        return INT_MAX;
    if (n == 0)
        return 0;
    if (dp[n][i] != -1)
        return dp[n][i];
    if (arr[i] == -1)
    {
        dp[n][i] = func(n, i - 1, dp, arr);
    }
    else
    {
        x = func(n - i, i, dp, arr);
        y = func(n, i - 1, dp, arr);
        dp[n][i] = min(x == INT_MAX ? INT_MAX : x + arr[i], y);
    }
    return dp[n][i];
}
int main(void)
{
    int t, n, k, i, result;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        vi arr(k + 1);
        vvi dp(k + 1, vi(k + 1, -1));
        for (i = 1; i <= k; i++)
            scanf("%d", &arr[i]);
        result = func(k, k, dp, arr);
        result == INT_MAX ? cout << -1 << endl : cout << result << endl;
    }
    char ch = getchar();
    ch = getchar();
    return 0;
}