class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        long long maxElement=LONG_MIN, maxDiff=LONG_MIN;

        for(int i=0; i<nums.size()-1; i++){
            maxElement= max(maxElement,(long long)nums[i]);
            maxDiff= max(maxDiff,maxElement-nums[i]);
            ans=max(ans,maxDiff*nums[i+1]);
        }
        return ans;
    }
};