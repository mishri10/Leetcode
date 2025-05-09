class Solution {
public:
    int helper(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(ind==coins.size()-1){
            if(amount%coins[ind]==0)
                return amount/coins[ind];
            return 100000;
        }

        if(dp[ind][amount]!=-1)
            return dp[ind][amount];

        int pick=INT_MAX;
        if(amount>=coins[ind])
            pick=1+helper(ind,coins,amount-coins[ind],dp);
        
        int notPick= helper(ind+1,coins,amount,dp);

        return dp[ind][amount]=min(pick,notPick);           
            
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= helper(0,coins,amount,dp);
        
        if(ans>=100000)
            return -1;
        return ans;
    }
};