#include <bits/stdc++.h>
using namespace std;


int solve(int i, int cost, int cnt, vector<int> &a, int k)
{
    if (cnt == k)
    {
        return cost;
    }
    if (i <0 || cnt > k)
    {
        return INT_MAX; // Invalid case
    }

    int ans = INT_MAX;

    if (a[i] != -1)
    {
        ans = min(ans, solve(i, cost + a[i], cnt + i + 1, a, k)); // take 1 i+1 kilo packet
    }
    ans = min(ans, solve(i - 1, cost, cnt, a, k)); // do not take 1 i+1 kilo packet

    return ans;

}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int n, k;
        cin >> n >> k;
       
        vector<int> a(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        int result = solve(k-1, 0, 0, a, k);
        if (result == INT_MAX)
            cout << -1 << endl; // If no valid solution exists
        else
            cout << result << endl;
    }
}
