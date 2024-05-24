class Solution {
public:
    int helper(int ind1,int ind2, string& text1, string& text2, 
               vector<vector<int>>& dp){
        
        if(ind1==text1.size() or ind2==text2.size())return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        int pick=0;
        
        //pick if
        
        if(text1[ind1]==text2[ind2]){
            pick=1+helper(ind1+1,ind2+1,text1,text2,dp);
        }
        
        int not_pick= max(helper(ind1+1,ind2,text1,text2,dp),
                          helper(ind1,ind2+1,text1,text2,dp));
        
        
        return dp[ind1][ind2]=max(pick,not_pick);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return helper(0,0,text1,text2,dp);
    }
};