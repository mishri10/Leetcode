class Solution {
public:
    int helper(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        
        
        if(ind==0){
            if(target%coins[0]==0)
                return target/coins[0];
            return 1e7;}
        
        if(dp[ind][target]!=-1)return dp[ind][target];
        
        int pick=1e7;
        
        if(target>=coins[ind]){
            pick=1+helper(ind,target-coins[ind],coins,dp);
        }
        int not_pick=helper(ind-1,target,coins,dp);
        
        return dp[ind][target]=min(pick,not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= helper(n-1,amount,coins,dp);
        return ans==1e7 ? -1:ans;
    }
};