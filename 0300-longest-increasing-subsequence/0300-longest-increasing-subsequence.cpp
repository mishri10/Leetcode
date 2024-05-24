class Solution {
public:
    int lis(int ind,int prev_ind, vector<int>& nums,vector<vector<int>>& dp){
        
        if(ind==nums.size())return 0;
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        
        int not_pick=lis(ind+1,prev_ind,nums,dp);
        int pick=0;
        
        if(prev_ind==-1 or nums[prev_ind]<nums[ind]){
            pick=1+lis(ind+1,ind,nums,dp);
        }
        
        return dp[ind][prev_ind+1]=max(pick,not_pick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return lis(0,-1,nums,dp);
    }
};