class Solution {
public:
    void helper(int ind, vector<int>& candidates, int target, 
                vector<int>& temp, vector<vector<int>>& ans){

                    if(target==0)
                        ans.push_back(temp);

                    for(int i=ind; i<candidates.size(); i++){
                        if(i!=ind and candidates[i]==candidates[i-1])
                            continue;
                        if(target>=candidates[i]){
                            temp.push_back(candidates[i]);
                            helper(i+1,candidates,target-candidates[i],
                            temp,ans);
                            temp.pop_back();
                        }
                    }


                }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,temp,ans);
        return ans;
    }
};