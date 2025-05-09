class Solution {
public:
    bool part(int ind, vector<int>& nums, int target, vector<vector<int>>& dp){

        if(target==0)
            return 1;

        if(ind==nums.size())
            return 0;

        if(dp[ind][target]!=-1)
            return dp[ind][target];

        int pick=0;

        if(target>=nums[ind])
            pick= part(ind+1,nums,target-nums[ind],dp);

        bool notPick= part(ind+1,nums,target,dp);

        return dp[ind][target]=pick or notPick;

    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto i: nums){
            sum+=i;
        }

        if(sum%2!=0)
            return 0;

        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        
        return part(0,nums,sum/2,dp);
    }
};

//1,1,2,3,4