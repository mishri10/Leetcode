class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=1; i<nums.size();i++){
            if(nums[i]==nums[i-1])
                cnt++;
            else{
                if(cnt%2!=0)
                    return 0;
                cnt=1;
            }
        }
        return 1;
    }
};