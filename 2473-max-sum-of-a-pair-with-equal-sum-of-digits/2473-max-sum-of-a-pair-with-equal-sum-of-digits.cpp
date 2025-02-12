class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>>mp;
        int ans=-1;
        int n=nums.size();

        for(int i=0; i<n; i++){
            int num=nums[i];
            int digitSum=0;
            while(num){
                digitSum+=(num%10);
                num/=10;
            }
            if(mp.find(digitSum)!=mp.end()){
                ans=max(ans,nums[i]+nums[mp[digitSum].back()]);
            }
            mp[digitSum].push_back(i);
        }
        return ans;
    }
};