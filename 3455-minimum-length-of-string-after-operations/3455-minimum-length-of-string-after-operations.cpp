class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int,int>mp;
        int ans=s.size();

        for(auto i:s){
            mp[i]++;
            if(mp[i]>2){
                ans-=2;
                mp[i]-=2;
            }
            }
        
        return ans;
    }
};
//a-->3, b-->4, c-->2