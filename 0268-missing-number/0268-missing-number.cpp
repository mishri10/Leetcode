class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr=0;
        for(int i=0;i<=nums.size();i++)
            xr^=i;
        for(auto i:nums){
            xr^=i;}
        
        return xr;
    }
};