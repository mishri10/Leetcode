class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //if min hea- is used the T.C: O(Nlogk) as there will be atmost k elements           in the heap
        
        
        //bucket sort approch
        //will make an array having size n+1 for covering all the case even when each element is unique
        
        //the bucket[i]=element where the element has freq i;
        
        
        
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<vector<int>>bucket(n+1);
        vector<int>ans;
        
        for(auto it:nums){
            mp[it]++;
        }
        
        for(auto it:mp){
            int freq=it.second;
            int val=it.first;
            bucket[freq].push_back(val);
        }
        
        
        for(int i=n;i>=0;--i){
            
           
            
            while(bucket[i].size()>0 and k>0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        
        return ans;
        
        
    }
};