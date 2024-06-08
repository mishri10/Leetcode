class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            int r=sum%k;
            if(i and r==0)return 1;
            if(mp.count(r)>0){ 
                if(i-mp[r]>1)
                    return 1;}
            else mp[r]=i;
        }
        return 0;
    }
};