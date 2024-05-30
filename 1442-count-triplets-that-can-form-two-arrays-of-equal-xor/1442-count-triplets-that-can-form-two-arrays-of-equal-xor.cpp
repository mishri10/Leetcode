class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
      
        int ans=0;
        
        int xr=0;
        mp[0].push_back(-1);

        
        for(int i=0;i<arr.size();i++){
            
            xr^=arr[i];
            
               
            
            if(mp.count(xr)){
                for(auto j:mp[xr])
                ans+=(i-(j+1));
            }
            
            mp[xr].push_back(i);
        }
        return ans;
    }
};