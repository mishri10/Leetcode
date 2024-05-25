class Solution {
public:
    void helper(int ind, string& s, unordered_set<string>st, vector<string>& ans,
                string temp){
        
        if(ind==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        string words="";
        for(int k=ind; k<s.size(); k++){
            
            words+=s[k];
            if(st.find(words)!=st.end()){
                
                helper(k+1,s,st,ans,temp+words+" ");
                
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto i:wordDict){
            st.insert(i);
        }
        
        vector<string>ans;
        string temp="";
        
        helper(0,s,st,ans,temp);
        return ans;
        
        
    }
};