class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int low=0;
        int high= nums.size()-1;

        while(low<=high){
            int mid= low+(high-low)/2;

            //leftSorted
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            //right sorted
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};