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
    int helper(TreeNode* node, int& dia){
        if(node==NULL)
            return 0;

        int lh=helper(node->left,dia);
        int rh=helper(node->right,dia);
        dia=max(dia,lh+rh);

        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        helper(root,dia);
        return dia;
    }
};