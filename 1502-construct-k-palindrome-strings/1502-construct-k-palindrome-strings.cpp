class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k)
            return 0;

        unordered_map<char,int>mp;

        for(auto ch: s){
            mp[ch]++;
        }
        int oddCnt=0;

        for(auto i: mp){
            if(i.second%2!=0){
                oddCnt++;
            }
        }

        return (oddCnt<=k);
    }
};