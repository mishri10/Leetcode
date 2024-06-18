/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* node, vector<vector<int>>& ans, vector<int>& temp){
        
        if(!node)return;
        
        temp.push_back(node->val);
        
        if(node->left==NULL and node->right==NULL){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        helper(node->left,ans,temp);
        helper(node->right,ans,temp);
        
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(root,ans,temp);
        vector<string>ans1;
        
       
        
        for(int i=0;i<ans.size();i++){
            string s="";
            for(int j=0; j<ans[i].size();j++){
                
                
                if(j==ans[i].size()-1){s+=to_string(ans[i][j]);break;}
                else{s+=to_string(ans[i][j]);
                s+="->";}
            }
            ans1.push_back(s);
        }
        
        return ans1;
    }
};