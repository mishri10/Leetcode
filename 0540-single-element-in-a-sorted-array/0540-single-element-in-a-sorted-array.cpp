class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //if mid is odd index and it similar element is on left then ans in right
        //if mid is even index and it similar element is on left then ans in left

        int n=nums.size();
        int lo=0;
        int hi=n-1;

        while(lo<=hi){
            int mid= lo+(hi-lo)/2;

            if(mid%2==1){
                if(mid-1>=0 and nums[mid-1]==nums[mid]){
                    lo=mid+1;
                }
                else
                    hi=mid-1;
            }

            else{
                if(mid-1>=0 and nums[mid-1]==nums[mid])
                    hi=mid-1;
                else
                    lo=mid+1;
            }
        }

        return nums[hi];
    }
};