class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0,sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r= (sum%k +(k))%k;
            
            if(mp.count(r)){
                ans+=mp[r];
            }
            
            mp[r]++;
        }
        return ans;
    }
};