class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int>left;
        unordered_map<char,int>right;
        unordered_set<string>ans;
        

        for(auto i:s)
            right[i]++;        


        for(int i=0; i<s.size(); i++){
                right[s[i]]--;
                if(right[s[i]]==0)
                    right.erase(s[i]);

                for(char expect='a'; expect<='z'; expect++){
                    if(left.count(expect) and right.count(expect)){
                        string temp;
                        temp+=expect;
                        temp+=s[i];
                        temp+=expect;
                        ans.insert(temp);
                    }
                        
                }

                left[s[i]]++;
        }
        return ans.size();
    }
};