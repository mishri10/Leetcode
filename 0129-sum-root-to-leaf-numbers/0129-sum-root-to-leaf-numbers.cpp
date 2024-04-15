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
    void preorder(TreeNode* root, int& ans, int sum){
        
        if(root==NULL)return;
        sum=sum*10+root->val;
        
        if(root->left==NULL and root->right==NULL)
            ans+=sum;
        
        preorder(root->left,ans,sum);
        preorder(root->right,ans,sum);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int ans=0;
        
        preorder(root,ans,sum);
        
        return ans;
    }
};