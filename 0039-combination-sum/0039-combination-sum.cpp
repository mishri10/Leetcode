class Solution {
public:
    void helper(int ind, vector<int>& candidates, int target, 
    vector<int>& temp, vector<vector<int>>& ans){
       
        if(ind==candidates.size()){
            if(target==0)
                ans.push_back(temp);
            return;

        }
        
        helper(ind+1,candidates,target,temp,ans);

        if(target>=candidates[ind]){
            temp.push_back(candidates[ind]);
            helper(ind,candidates,target-candidates[ind],temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,candidates,target,temp,ans);
        return ans;
    }
};