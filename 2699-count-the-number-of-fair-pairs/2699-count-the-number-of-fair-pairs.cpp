class Solution {
public:
    //long long find() //1,2,5,7,9
    long long lower_bound(int s, int x, vector<int>& nums){
        long long ans=-1;
        //greater than equal to
        int start=s;
        int end= nums.size()-1;

        while(start<=end){
            int mid= start+ (end-start)/2;
            if(nums[mid]>=x){
                ans= mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }

    long long upper_bound(int s, int x, vector<int>& nums){
        long long ans=-1; ////1,2,5,7,9
        //less than equal to
        int start=s;
        int end= nums.size()-1;

        while(start<=end){
            int mid= start+ (end-start)/2;
            if(nums[mid]<=x){
                ans= mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }


    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long cnt=0;
        for(int i=0; i<n; i++){
            int element= nums[i];
            int lowerInd= lower_bound(i+1,lower-element,nums);
            int upperInd= upper_bound(i+1,upper-element,nums);
            if(lowerInd!=-1 and upperInd!=-1)
                cnt+= (upperInd-lowerInd+1);
        }
        return cnt;
    }
};
// [1,7,9,2,5]
//  1,2,5,7,9  