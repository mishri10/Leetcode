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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool leftToRight=1;
        vector<vector<int>>ans;
        
        if(!root)return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>temp(n,0);
            
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(leftToRight)temp[i]=node->val;
                if(!leftToRight)temp[n-i-1]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(temp);
            leftToRight=!leftToRight;
        }
        return ans;
        
        
    }
};