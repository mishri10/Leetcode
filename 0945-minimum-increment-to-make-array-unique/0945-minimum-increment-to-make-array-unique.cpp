class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int operation=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                nums[i]+=1;
                operation++;
            }
            
            else if(nums[i]<nums[i-1]){
                int target= nums[i-1]+1;
                operation+=(target-nums[i]);
                nums[i]=target;
            }
        }
        return operation;
    }
};