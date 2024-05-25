class Solution {
public:
    int helper(int i, int j, string word1, string word2, vector<vector<int>>& dp){
        //base case
        
        if(i<0)return j+1;
        if(j<0)return i+1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int pick=1e7;
        
        if(word1[i]==word2[j]){
            pick=helper(i-1,j-1,word1,word2,dp);
        }
        
        int not_pick=min(1+helper(i,j-1,word1,word2,dp), 
                         min(1+helper(i-1,j,word1,word2,dp),                                                        1+helper(i-1,j-1,word1,word2,dp)));
        
        return dp[i][j]=min(pick, not_pick);
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return helper(n-1,m-1,word1,word2,dp);
        
    }
};