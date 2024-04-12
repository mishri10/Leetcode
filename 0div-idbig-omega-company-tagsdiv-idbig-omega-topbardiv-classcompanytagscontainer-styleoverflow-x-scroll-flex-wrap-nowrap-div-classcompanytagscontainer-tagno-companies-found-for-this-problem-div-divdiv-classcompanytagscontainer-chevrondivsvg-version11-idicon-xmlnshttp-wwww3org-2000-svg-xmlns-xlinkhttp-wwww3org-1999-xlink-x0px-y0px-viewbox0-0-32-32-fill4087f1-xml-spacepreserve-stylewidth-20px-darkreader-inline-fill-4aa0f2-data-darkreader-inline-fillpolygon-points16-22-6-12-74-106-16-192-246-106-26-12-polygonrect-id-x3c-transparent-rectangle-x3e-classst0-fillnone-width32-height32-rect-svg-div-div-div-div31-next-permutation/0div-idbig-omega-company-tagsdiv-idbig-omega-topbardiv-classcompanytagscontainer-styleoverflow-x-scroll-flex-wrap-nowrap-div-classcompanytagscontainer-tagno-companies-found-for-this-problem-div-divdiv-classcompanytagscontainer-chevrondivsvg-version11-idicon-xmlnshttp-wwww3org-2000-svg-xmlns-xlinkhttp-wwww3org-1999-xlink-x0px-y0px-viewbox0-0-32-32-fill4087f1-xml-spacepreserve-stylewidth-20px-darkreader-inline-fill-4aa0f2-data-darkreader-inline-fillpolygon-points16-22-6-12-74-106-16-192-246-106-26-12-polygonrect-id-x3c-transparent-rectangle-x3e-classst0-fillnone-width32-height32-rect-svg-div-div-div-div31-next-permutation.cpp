class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int n=nums.size();
        
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        
        if(i<0){
            sort(nums.begin(),nums.end());
            return;
        }
        
        for(int j=n-1;j>=0;j--){
            if(nums[j]>nums[i]){
                swap(nums[j],nums[i]);
                break;
            }
                
        }
        
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};