class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int len1=1;
        int len2=1;
        

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]>nums[i]){
                len1++;
                len2=1;
            }
            else if(nums[i+1]<nums[i]){
                len1=1;
                len2++;
            }
            else{
                len1=1;
                len2=1;
            }
            ans=max(ans,max(len1,len2));
        }

        return ans;

        
    }
};