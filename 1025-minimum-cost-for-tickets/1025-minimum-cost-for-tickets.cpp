class Solution {
public:
    int helper(int ind, int daysCovered, vector<int>& costs, vector<int>& days,
                vector<vector<int>>& dp){
        if(ind==days.size())
            return 0;
        if(dp[ind][daysCovered]!=-1)
            return dp[ind][daysCovered];

        int cnt0=INT_MAX;
        int cnt1=INT_MAX;
        int cnt2=INT_MAX;
        int cnt3= INT_MAX;

        if(daysCovered>=days[ind]){
            cnt0= helper(ind+1,daysCovered,costs,days,dp);
        }

        else{
            cnt1= costs[0]+ helper(ind+1,days[ind],costs,days,dp);
            cnt2= costs[1]+ helper(ind+1,days[ind]+6,costs,days,dp);
            cnt3= costs[2]+ helper(ind+1,days[ind]+29,costs,days,dp);
        }

        return dp[ind][daysCovered]=min(min(cnt0,cnt1),min(cnt2,cnt3));
    }
//rate limiting algo, bst, greedy, dp, greedy, dbms, bst--> range based seasrch, normal based search, string matching

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<vector<int>>dp(n,vector<int>(400,-1));
        return helper(0,0,costs,days,dp);
    }
};