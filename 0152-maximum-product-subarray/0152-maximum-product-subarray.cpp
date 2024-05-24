class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int pre=1,suffix=1;
        for(int i=0;i<nums.size();i++){
            
            if(pre==0)pre=1;
            if(suffix==0)suffix=1;
            
            pre*=nums[i];
            suffix*=nums[n-i-1];

            
            ans=max(ans,max(pre,suffix));
        }
        return ans;
    }
};