class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high= n-1;

        while(low<=high){
            int mid= low+(high-low)/2;

            if(nums[mid]==target)
                return 1;

            while(low<mid and nums[low]==nums[mid]){
                low++;
            }

            while(high>mid and nums[high]==nums[mid]){
                high--;
            }

            //left side is sorted
            if(nums[low]<=nums[mid]){
                if(target>=nums[low] and target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }

            //right side is sorted
            else{
                if(target>nums[mid] and target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
            
        }
        return 0;
    }
};