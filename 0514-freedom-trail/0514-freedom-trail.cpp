class Solution {
public:
    int helper(string& ring, string& key, int r, int k, vector<vector<int>>& dp){
        
        
        int n=ring.size();
        int m=key.size();
        if(k>=m)return 0;
        if(dp[r][k]!=-1)return dp[r][k];
        
        int step=1e7;
        for(int i=0;i<n;i++){
            if(ring[i]==key[k]){
                step=min(step,min(abs(r-i),n-abs(r-i))+1+helper(ring,key,i,k+1,dp));
            }
        }
        return dp[r][k]=step;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int m=key.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int r=0,k=0;
        return helper(ring,key,r,k,dp);
    }
};