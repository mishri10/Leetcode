class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        
        
        int pt=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int num=it->first;
            int freq=it->second;
            
            while(freq--){
                nums[pt++]=num;
            }
        }
        return;
    }
};
