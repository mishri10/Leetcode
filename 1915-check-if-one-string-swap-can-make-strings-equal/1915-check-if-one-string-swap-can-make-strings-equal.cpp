class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        vector<int>freq(26,0);
        for(int i=0; i<s1.size(); i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
            if(s1[i]!=s2[i]){
                cnt++;
            }
            if(cnt>2)
                return 0;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                return 0;
        }
        return (cnt==0 or cnt==2);
    }
};