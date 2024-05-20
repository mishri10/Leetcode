class Solution {
public:
    void helper(int ind,vector<int>& nums,int& xr,int& ans){
        if(ind==nums.size()){
            ans+=xr;
            return;
        }
        
        xr^=nums[ind];
        helper(ind+1,nums,xr,ans);
        xr^=nums[ind];
        
        helper(ind+1,nums,xr,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int xr=0;
        helper(0,nums,xr,ans);
        return ans;
        
    }
};