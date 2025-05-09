class Solution {
public:
    int LCS(int ind1, int ind2, string& text1, string& text2, 
            vector<vector<int>>& dp){

        if(ind1>= text1.size() or ind2>=text2.size())
            return 0;

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        int pick=0;

        if(text1[ind1]==text2[ind2])
            pick= 1+ LCS(ind1+1,ind2+1,text1,text2,dp);

        int notPick=max(LCS(ind1+1,ind2,text1,text2,dp),
                        LCS(ind1,ind2+1,text1,text2,dp));


        return dp[ind1][ind2]=max(pick,notPick);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return LCS(0,0,text1,text2,dp);
    }
};