class Solution {
public:
    bool helper(int ind, string s, unordered_set<string>& st, int n, vector<int>& dp){
        if(ind==n)
            return 1;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        
        for(int i=ind; i<n; i++){
            string temp= s.substr(ind,i-ind+1);
            if(st.count(temp))
                if(helper(i+1,s,st,n,dp))
                    return dp[ind]=1;     
        }
        return dp[ind]=0;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        int n=s.size();
        
        vector<int>dp(n,-1);        
        
        return helper(0,s,st,n,dp);
    }
};