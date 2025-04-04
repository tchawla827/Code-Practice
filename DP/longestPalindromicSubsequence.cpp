class Solution {
    public:
        int help(string &s,int l,int r,vector<vector<int>>&memo)
        {
            if(l>r) return 0;
            if(memo[l][r]!=-1) return memo[l][r];
            if(s[l]==s[r])
            {
                if(l!=r)
                return memo[l][r]=2+help(s,l+1,r-1,memo);
                else
                return memo[l][r]=1+help(s,l+1,r-1,memo);
            }
            else
            {
                int opt1=help(s,l+1,r,memo);
                int opt2=help(s,l,r-1,memo);
                return memo[l][r]=max(opt1,opt2);
            }
            return 0;
        }
    
        int longestPalindromeSubseq(string s) {
            vector<vector<int>> memo(s.size(),vector<int>(s.size(),-1));
            return help(s,0,s.size()-1,memo);
        }
    };