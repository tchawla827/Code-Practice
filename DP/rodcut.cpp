#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int len = i + 1; // Rod piece length
            int inc = (j >= len) ? price[i] + dp[i][j - len] : 0; // Include case
            int exc = (i > 0) ? dp[i - 1][j] : 0; // Exclude case
            dp[i][j] = max(inc, exc);
        }
    }

    return dp[n - 1][n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    int ans = cutRod(price);
    cout << ans << endl;
}
