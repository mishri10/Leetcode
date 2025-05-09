class Solution {
public:
    int helper(int i, int j, string& word1, string& word2, int n, int m, 
                vector<vector<int>>& dp){
        if(j<0)
            return i+1;
        if(i<0)
            return j+1;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int similar=INT_MAX;

        if(word1[i]==word2[j])
            similar=helper(i-1,j-1,word1,word2,n,m,dp);
        
        int deletee= 1+helper(i-1,j,word1,word2,n,m,dp);
        int insert = 1+helper(i,j-1,word1,word2,n,m,dp);
        int replace= 1+helper(i-1,j-1,word1,word2,n,m,dp);

        return dp[i][j]=min(min(similar,deletee),min(insert,replace));
    }

    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,word1,word2,n,m,dp);
    }
};
// p1,p2
// Similar p1-1,p2-1 
// insert p1,p2-1
// delete p1-1,p2
// replace p1-1, p2-1
// when p2<0
   // return p1
// when 
   //return 1e5