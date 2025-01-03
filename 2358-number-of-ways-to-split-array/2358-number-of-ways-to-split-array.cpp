class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        long long currSum=0;
        int ans=0;

        for(auto i: nums)
            sum+=i;
        
        for(int i=0; i<=nums.size()-2; i++){
            currSum+=nums[i];   

            if(currSum>=sum-currSum)
                ans++;
        }
        return ans;
    }
};