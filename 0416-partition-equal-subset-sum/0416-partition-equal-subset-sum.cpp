class Solution {
public:
    bool Partition(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        
        if(ind==nums.size()){
            if(target==0)return 1;
            return 0;
        }
        
        if(dp[ind][target]!=-1)return dp[ind][target];
        
        bool pick=0;
        if(target>=nums[ind])            
            pick=Partition(ind+1,target-nums[ind],nums,dp);
        
        bool not_pick=Partition(ind+1,target,nums,dp);
        
        return dp[ind][target]=pick or not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(auto it:nums)sum+=it;
        
        if(sum%2!=0)return 0;
        sum=sum>>1;
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        
        return Partition(0,sum,nums,dp);
        
    }
};