class Solution {
public:
    int longest(int ind, int prev, string& s, int k, vector<vector<int>>& dp) {
        if (ind >= s.size()) return 0;
        
        char curr = s[ind];
        if (dp[ind][prev] != -1) return dp[ind][prev];
        
        int pick = 0;
        if (prev == 0 || abs(prev - curr) <= k)
            pick = 1 + longest(ind + 1, curr, s, k, dp);
        
        int not_pick = longest(ind + 1, prev, s, k, dp);
        
        return dp[ind][prev] = max(pick, not_pick);
    }
    
    int longestIdealString(string s, int k) {
        
        vector<vector<int>> dp(s.size() + 1, vector<int>(150, -1)); 
        return longest(0, 0, s, k, dp);
    }
};
