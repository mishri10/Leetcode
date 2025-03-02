class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;

        for(auto it: nums1){
            int idx= it[0];
            int val= it[1];
            mp[idx]=val;
        }

        for(auto it: nums2){
            int idx= it[0];
            int val= it[1];
            if(mp.count(idx))
                mp[idx]+=val;
            else
                mp[idx]=val;
        }

        vector<vector<int>>ans;

        for(auto it: mp){
            int idx= it.first;
            int val= it.second;
            ans.push_back({idx,val});
        }

        return ans;        
    }
};