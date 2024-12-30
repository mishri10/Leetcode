class Solution {
public:
    int mod= 1e9+7;
    

    int solve(int len, int low, int high, int zero, int one, vector<int>& dp){
        if(len>high)
            return 0;

        if(dp[len]!=-1)
            return dp[len];

        int ans=0;

        if(len>=low)
            ans+=1;
        
        int includeZero= solve(len+zero,low,high,zero,one,dp);
        int includeOne=  solve(len+one,low,high,zero,one,dp);

        return dp[len]= (ans+includeZero+includeOne)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return solve(0,low,high,zero,one,dp);

    }
};