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
    int heightofTree(TreeNode* node, int& dia){
        if(node==NULL)
            return 0;
        
        int lh= heightofTree(node->left,dia);
        int rh= heightofTree(node->right,dia);

        dia=max(dia,lh+rh);

        return 1+max(lh,rh);
    }

    void inorder(TreeNode* root, int& ans){
        if(root==NULL)
            return;

        inorder(root->left,ans);
        int dia=0;
        heightofTree(root,dia);
        ans=max(ans,dia);
        inorder(root->right,ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        inorder(root,ans);
        return ans;
    }
};