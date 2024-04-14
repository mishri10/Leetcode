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
    bool isLeaf(TreeNode* node){
        return node->left==NULL and node->right==NULL;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        
        
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left){
                    if(isLeaf(node->left))ans+=node->left->val;
                    q.push(node->left);}
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        
        return ans;
        
    }
};