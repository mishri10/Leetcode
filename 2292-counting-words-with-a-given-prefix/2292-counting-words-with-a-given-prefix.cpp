class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size();
        int cnt=0;

        for(auto i: words){
            if(i.substr(0,n)==pref)
                cnt++;
        }
        return cnt;
    }
};