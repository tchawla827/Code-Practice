class Solution
{
public:
    
    int help(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
    {
        
        if (i + 1 == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, help(cuts, i, k, dp) + help(cuts, k, j, dp) + (cuts[j] - cuts[i]));
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int> &cuts)
    {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return help(cuts, 0, m - 1, dp);
    }
};
