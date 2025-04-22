class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int l=0,r=0;
        int n=s.size();
        unordered_map<char,int>mp;

        while(r<n){
            mp[s[r]]++;
            while(mp.size()!=r-l+1){
                mp[s[l]]--;
                if(mp[s[l]]==0)
                    mp.erase(s[l]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};