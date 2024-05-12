class Solution {
public:
    
    void helper(int ind,string& s,vector<string>&temp,vector<vector<string>>& ans){
        
        if(ind==s.size()){
            ans.push_back(temp);
        }
        
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s.substr(ind,i-ind+1))){
                temp.push_back(s.substr(ind,i-ind+1));
                helper(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>>ans;
        
        helper(0,s,temp,ans);
        return ans;
    }
    
    bool isPalindrome(string temp){
        int n=temp.size();
        
        for(int i=0;i<n/2;i++){
            if(temp[i]!=temp[n-i-1])return 0;
        }
        return 1;
    }
};