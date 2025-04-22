class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        int sum=0;
        mp[0]=1;

        for(auto i: nums){
            sum+=i;
            int comp=(sum-k);
            if(mp.find(comp)!=mp.end()){
                ans+=mp[comp];
            }
            mp[sum]++;
        }
        return ans;
    }
};