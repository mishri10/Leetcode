class Solution {
public:
    bool check(string a, string b){
        if(b.substr(0,a.size())== a and b.substr(b.size()-a.size())==a)
            return 1;
        return 0;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(check(words[i],words[j]))
                    ans++;
            }
        }
        return ans;
    }
};