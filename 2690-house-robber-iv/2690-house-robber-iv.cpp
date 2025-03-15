class Solution {
public:
    bool isPossible(vector<int>& nums, int& mid, int k){
        int i=0;

        while(i<nums.size()){
            if(nums[i]<=mid){
                k--;
                i+=2;
            }
            else{
                i++;
            }
        }
        return k<=0;
    }

    int minCapability(vector<int>& nums, int k) {
        int n= nums.size();
        int low=INT_MAX;
        int high= INT_MIN;
        for(auto i: nums){
            low=min(low,i);
            high=max(high,i);
        }
        int ans=0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(isPossible(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};