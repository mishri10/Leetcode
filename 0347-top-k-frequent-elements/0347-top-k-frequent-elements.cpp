class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // N^2 + O(K) --> Brute force
        // unordered_map, priority_queue O(N)+O(NlogN) --> better
        // unordered_map, bucket where index represent freq O(N)+ O(N) + O(K) bucket sort --> optimal

        unordered_map<int,int>mp;

        for(auto i: nums)
            mp[i]++;
            
        int n=nums.size();

        vector<vector<int>>freq(n+1);

        for(auto i: mp)
            freq[i.second].push_back(i.first);

        vector<int>ans;

        for(int i= n; i>=0; i--){
            if(freq[i].size()!=0){
                int j=0;

                while(j<freq[i].size() and k>0){
                    ans.push_back(freq[i][j]);
                    j++;
                    k--;
                }
            }

        }

        return ans;
    }
};