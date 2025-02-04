class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum=nums[0];
        int ans=0;
        int n=nums.size();

        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i])
                currSum+=nums[i];
            else{
                ans=max(ans,currSum);
                currSum=nums[i];
            }
        }
        ans=max(ans,currSum);
        return ans;
    }
};