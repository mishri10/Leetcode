class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                if(i+1<n and nums[i+1]%2==0)
                    return 0;
            }
            else{
                if(i+1<n and nums[i+1]%2!=0)
                    return 0;
            }
        }
        return 1;
    }
};