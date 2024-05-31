class Solution {
public:
    
    void combinations(int ind,vector<int>& candidates, int target, vector<int>& temp,                       vector<vector<int>>& ans){
        
        //base case
       
       
            if(target==0){
                ans.push_back(temp);
                return;}
        
        
        for(int i=ind;i<candidates.size();i++){   
    
        if(i!=ind and candidates[i]==candidates[i-1])continue;
        if(target>=candidates[i]){
        temp.push_back(candidates[i]);
        combinations(i+1,candidates,target-candidates[i],temp,ans);
        temp.pop_back();}
        }
        
        
    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
       
        
        sort(candidates.begin(),candidates.end());
        combinations(0,candidates,target,temp,ans);
               
        return ans;
        
    }
};

// [10,1,2,7,6,1,5]
// [1,1,2,5,6,7,10]
// [1,5]-->6
// [1,2,3]-->6
    
//T.C: O(N*target)
//S.C: O(N*target)+O(N)