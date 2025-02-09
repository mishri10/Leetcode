class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long totalPair=(n*(n-1))/2;
        unordered_map<long long,long long>mp;

        for(int i=0; i<n; i++){
            long long diff= nums[i]-i;
            totalPair-=mp[diff];
            mp[diff]++;
        }

        return totalPair;
    }
};
