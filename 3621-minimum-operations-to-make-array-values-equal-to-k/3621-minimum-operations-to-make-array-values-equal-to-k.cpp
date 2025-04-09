class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i: nums){
            if(i<k) 
                return -1;
            mp[i]++;
        }
        if(mp.count(k)>0)
            return mp.size()-1;
            
        return mp.size();
    }
};