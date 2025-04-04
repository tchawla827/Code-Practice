class Solution {
    public:
        int help(string &s,string &t,int i,int j,vector<vector<int>>&memo)
        {
            if(j==-1) return 1;
            if(i<0) return 0;
            if(memo[i][j]!=-1) return memo[i][j];
    
            if(s[i]==t[j])
            {
                int c1=help(s,t,i-1,j-1,memo);
                int c2=help(s,t,i-1,j,memo);
    
                return memo[i][j]=c1+c2;
            }
            else
            {
                return memo[i][j]=help(s,t,i-1,j,memo);
            }
        }
    
        int numDistinct(string s, string t) 
        {
            if(t.size()>s.size()) return 0;
            if(t.size()==s.size())
            {
                for(int i=0;i<t.size();i++)
                {
                    if(s[i]!=t[i]) return 0;
                }
                return 1;
            }
            vector<vector<int>> memo(s.size(),vector<int>(t.size(),-1));
            return help(s,t,s.size()-1,t.size()-1,memo);
        }
    };