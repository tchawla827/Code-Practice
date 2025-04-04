class Solution {
    public:
        int help(vector<int>&nums,int ind,int last,vector<vector<int>> &memo)
        {
            if(ind==nums.size()) return 0;
    
            if(memo[ind][last+1]!=-1) return memo[ind][last+1];
    
            if(last==-1 || nums[ind]>nums[last])
            {
                int opt1= 1+help(nums,ind+1,ind,memo);
                int opt2= help(nums,ind+1,last,memo);
    
                return memo[ind][last+1]=max(opt1,opt2);
            }
            else
            {
                return memo[ind][last+1]=max(0,help(nums,ind+1,last,memo));
            }
        }
    
        int lengthOfLIS(vector<int>& nums) {
            vector<vector<int>> memo(nums.size(),vector<int>(nums.size()+1,-1));
            return help(nums,0,-1,memo);
        }
    };