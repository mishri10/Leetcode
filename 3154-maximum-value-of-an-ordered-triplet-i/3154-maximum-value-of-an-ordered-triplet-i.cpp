class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       int n=nums.size();

       long long maxElement=LONG_MIN, maxDiff=LONG_MIN;
       long long ans=0;

       for(int i=0; i<n-1; i++){
        maxElement=max(maxElement,(long long)nums[i]);
        maxDiff= max(maxDiff, maxElement-nums[i]);
        ans= max(maxDiff*nums[i+1],ans);
       }

       return ans;
    }
};