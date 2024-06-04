class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto it:s)
            mp[it]++;
        
        int ans=0;
        int odd=0;
        
        for(auto it:mp){
            if(it.second>=2){
                if(it.second%2==1)ans+=(it.second-1);
                else ans+=it.second;}
            if(it.second%2==1) odd++;
        }
        
        if(odd)ans++;
        return ans;
     }
};