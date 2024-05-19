class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0,cnt=0;
        int d=INT_MAX;
        
        
        for(auto i:nums){
            if((i^k)>i){
                sum+=i^k;
                cnt++;
                d=min(d,(i^k)-i);
            }
            else{
                sum+=i;
                d=min(d,i-(i^k));
            }
        }
        
        if(cnt%2==0)return sum;
        return sum-d;
    }
};