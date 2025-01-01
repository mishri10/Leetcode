class Solution {
public:
    void helper(int ind, int target, vector<int>& candidates, vector<int>& temp,
                vector<vector<int>>& ans){

            if(target==0){
                ans.push_back(temp);
                return;
            }

            if(ind==candidates.size())
                return;
            

            if(candidates[ind]<=target){
                temp.push_back(candidates[ind]);
                helper(ind,target-candidates[ind],candidates,temp,ans);
                temp.pop_back();
            }

            helper(ind+1,target,candidates,temp,ans);
            
            }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        helper(0,target,candidates,temp,ans);
        return ans;
    }
};