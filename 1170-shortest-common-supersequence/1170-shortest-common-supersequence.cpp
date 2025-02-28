class Solution {
public:
    int helper(int i,int j,string& s1, string&s2,vector<vector<int>>& dp){
        
        if(i==s1.size() or j==s2.size())return 0;
        
        //overlapping subproblem
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i]==s2[j])return dp[i][j]=1+helper(i+1,j+1,s1,s2,dp);
        
        return dp[i][j]= max(helper(i+1,j,s1,s2,dp),helper(i,j+1,s1,s2,dp));
        
        
        
    }
    string shortestCommonSupersequence(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        helper(0,0,s1,s2,dp);
        
        string ans;
        
        int i=0,j=0;
        
        while(i<n and j<m){
            if(s1[i]==s2[j]){
                ans+=s1[i];
                i++;j++;
            }
            
            else if(dp[i+1][j]>dp[i][j+1]){ans+=s1[i];i++;}
            else{ans+=s2[j];j++;}
        }
        
        while(i<n)ans+=s1[i++];
        while(j<m)ans+=s2[j++];       

        return ans;
    }
};