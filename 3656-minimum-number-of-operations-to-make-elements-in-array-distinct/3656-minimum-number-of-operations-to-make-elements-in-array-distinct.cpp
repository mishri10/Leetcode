class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int t=0;
        int rem=n;

        for(auto i: nums)
            mp[i]++;

        if(mp.size()==n)
            return t;

        for(int i=0; i<n; i+=3){
            if(i+2>=n)
                return ++t;
            else{
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                mp[nums[i+1]]--;
                if(mp[nums[i+1]]==0)mp.erase(nums[i+1]);
                mp[nums[i+2]]--;
                if(mp[nums[i+2]]==0)mp.erase(nums[i+2]);
                t++;
                rem-=3;
                if(mp.size()==rem)
                    return t;
            }
        }
        return t;

          
    }
};