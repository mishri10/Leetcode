class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(auto i: s){
            if(i>='0' and i<='9' and ans.size()!=0)
                ans.pop_back();
            else
                ans.push_back(i);
        }
        return ans;
    }
};