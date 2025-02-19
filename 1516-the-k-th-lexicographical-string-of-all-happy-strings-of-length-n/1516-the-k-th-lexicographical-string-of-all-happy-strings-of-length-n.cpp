class Solution {
public:
    void helper(string& temp, vector<string>& ans, int prev, int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<=2; i++){
            if(i!=prev){
                temp.push_back(i+'a');
                helper(temp,ans,i,n);
                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string>ans;
        string temp;
        int prev=11;

        helper(temp,ans,prev,n);
        if(ans.size()<k)
            return "";
        return ans[k-1];
    }
};